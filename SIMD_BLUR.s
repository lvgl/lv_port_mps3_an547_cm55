

            .section .text
            .balign 4

.globl blur_filter_asm
blur_filter_asm:
// void blur_filter_asm(int8_t *pt32, const int16_t iWidth, const int32_t inc, const int shifts);
//                              R0                   R1         R2              R3   
//        pt8 = (unsigned char *)pt32;     /* read RGBA 8888  */
//        accuR = *pt8++;
//        accuG = *pt8++;
//        accuB = *pt8++;
//        for (iX = 0; iX < iWidth; iX++)
//            accuR += (((*pt8)-accuR)>>s1) + (((*pt8)-accuR)>>s2) + (((*pt8)-accuR)>>s3); *pt8++ = accuR;
//            accuG += (((*pt8)-accuG)>>s1) + (((*pt8)-accuG)>>s2) + (((*pt8)-accuG)>>s3); *pt8++ = accuG;
//            accuB += (((*pt8)-accuB)>>s1) + (((*pt8)-accuB)>>s2) + (((*pt8)-accuB)>>s3); *pt8++ = accuB;
//            pt8++;                  /* skip A */

// register allocation
// r0  = pointer 
// r1  = iwidth
// r2  = increment
// r3  = 
// r4  = tmp2
// r5  = s2
// r6  = m2
// r7  = s1
// r8  = m1
// r9  = tmp
// r10 = input
// r11 = accuRGBA
// r12 = input mask

    push {r4, r5, r6, r7, r8, r9, r10, r11, r12}
    
    lsl     r2, r2, 2               // W32 increment to byte increment
    sxtb    r7, r3                  // s1
    sxtb    r5, r3, ror #8          // s2
    
    mov     r9, #0xFF
    lsl     r9, r9, r7              // mask1
    and     r9, r9, #0xFF
    mov     r8, #0
    orr     r8, r8, r9, lsl #0
    orr     r8, r8, r9, lsl #8
    orr     r8, r8, r9, lsl #16
    orr     r8, r8, r9, lsl #24     // mask1 

    mov     r9, #0xFF
    lsl     r9, r9, r5              // mask2
    and     r9, r9, #0xFF
    mov     r6, #0
    orr     r6, r6, r9, lsl #0
    orr     r6, r6, r9, lsl #8
    orr     r6, r6, r9, lsl #16
    orr     r6, r6, r9, lsl #24     // mask2 
    
    mov     r9, #0xFC    
    orr     r12, r12, r9, lsl #0
    orr     r12, r12, r9, lsl #8
    orr     r12, r12, r9, lsl #16
    orr     r12, r12, r9, lsl #24   // input maskin   
    
    ldr     r11, [r0]               // r11 = accu
    and     r11, r11, r12           // r11 = in & mask_input
    lsr     r11, r11, 2             // r11 = (in >> 2)
    
    
L_blurLoop:                  

    ldr     r10, [r0]               // r10 = input RGBA
    and     r10, r10, r12           // r10 = in & mask_input
    lsr     r10, r10, 2             // r10 = (in >> 2)
    
    and     r9, r10, r8             // r9 = in & mask1
    lsr     r9, r9, r7              // r9 = (in >> s1)
    and     r4 , r11, r8            // r4= accu & mask1
    lsr     r4 , r4 , r7            // r4= (accu >> s1)
    qadd8   r11, r11, r9            // accu += (in>>s1)
    qsub8   r11, r11, r4            // accu -= (in>>s1)

    and     r9, r10, r6             // r9 = in & mask2
    lsr     r9, r9, r5              // r9 = (in >> s2)
    and     r4 , r11, r6            // r4= accu & mask2
    lsr     r4 , r4 , r5            // r4= (accu >> s2)
    qadd8   r11, r11, r9            // accu += (in>>s2)
    qsub8   r11, r11, r4            // accu -= (in>>s2)

    lsl     r9, r11, 2              // r9 = 4 x accu 
    str     r9, [r0]                // save RGBA
    add     r0, r0, r2              // pt32 increment
    
    subs    r1, r1, #1         
    bne     L_blurLoop

    ldmia.w sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12}
    bx     lr
    .end
