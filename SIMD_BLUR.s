

            .section .text
            .balign 4

.globl blur_filter_asm
blur_filter_asm:
// void blur_filter_asm(int8_t *pt32, const int16_t iWidth, const int32_t inc, const int8_t ratio);
//                              R0                   R1         R2              R3   
//        pt8 = (unsigned char *)pt32;     /* read RGBA 8888  */
//        accuR = *pt8++;
//        accuG = *pt8++;
//        accuB = *pt8++;
//        for (iX = 0; iX < iWidth; iX++)
//            accuR += ((*pt8) - accuR) * ratio >> 8;  *pt8++ = accuR;
//            accuG += ((*pt8) - accuG) * ratio >> 8;  *pt8++ = accuG;
//            accuB += ((*pt8) - accuB) * ratio >> 8;  *pt8++ = accuB;
//            pt8++;                  /* skip A */

// register allocation
// r0  = pointer 
// r1  = iwidth
// r2  = increment
// r3  = ratio
// r4  = tmp1
// r5  = Raccu
// r6  = Gaccu
// r7  = Baccu
// r8  = m1
// r9  = out
// r10 = input
// r11 = 
// r12 = 

    push {r4, r5, r6, r7, r8, r9, r10, r11, r12}
    
    lsl     r2, r2, 2               // W32 increment to byte increment
     
    ldr     r4, [r0]                // tmp1 = accu
    uxtb    r5, r4                  // Raccu
    uxtb    r6, r4, ror #8          // Gaccu
    uxtb    r7, r4, ror #16         // Baccu
    
L_blurLoop:                  

    ldr     r10, [r0]               // r10 = input RGBA
    uxtb    r4, r10                 // tmp1 = Rin(R)
    sub     r4, r4, r5              // tmp1 = Rin - Raccu
    mul     r4, r4, r3              // tmp1 = (Rin - Raccu) * ratio
    asr     r4, #8                  // tmp1 = (Rin - Raccu) * ratio >> 8
    add     r5, r5, r4              // Raccu += (Rin - Raccu) * ratio >> 8
    and     r9, r5, #255            // out[0] = Raccu
    
    uxtb    r4, r10, ror #8         // tmp1 = Rin(G)
    sub     r4, r4, r6              // tmp1 = Gin - Gaccu
    mul     r4, r4, r3              // tmp1 = (Gin - Gaccu) * ratio
    asr     r4, #8                  // tmp1 = (Gin - Gaccu) * ratio >> 8
    add     r6, r6, r4              // Gaccu += (Gin - Gaccu) * ratio >> 8
    orr     r9, r6, lsl #8          // out[1] = Gaccu
    
    uxtb    r4, r10, ror #16        // tmp1 = Rin(B)
    sub     r4, r4, r7              // tmp1 = Bin - Baccu
    mul     r4, r4, r3              // tmp1 = (Bin - Baccu) * ratio
    asr     r4, #8                  // tmp1 = (Bin - Baccu) * ratio >> 8
    add     r7, r7, r4              // Baccu += (Bin - Baccu) * ratio >> 8
    orr     r9, r7, lsl #16         // out[2] = Baccu
    
    asr     r4, r10, #24            // tmp1 = Rin>>24 (alpha)
    orr     r9, r4, lsl #24         // out[3] = alpha

    str     r9, [r0]                // save RGBA
    add     r0, r0, r2              // pt32 increment
    
    subs    r1, r1, #1         
    bne     L_blurLoop

    ldmia.w sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12}
    bx     lr
    .end
