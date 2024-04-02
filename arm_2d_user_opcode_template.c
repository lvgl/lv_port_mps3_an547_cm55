/*
 * Copyright (c) 2009-2024 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*============================ INCLUDES ======================================*/
#define __ARM_2D_IMPL__

#include "arm_2d.h"
#include "__arm_2d_impl.h"

#include "arm_2d_user_opcode_template.h"

#ifdef   __cplusplus
extern "C" {
#endif

#if defined(__clang__)
#   pragma clang diagnostic ignored "-Wunknown-warning-option"
#   pragma clang diagnostic ignored "-Wreserved-identifier"
#   pragma clang diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
#   pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#   pragma clang diagnostic ignored "-Wcast-qual"
#   pragma clang diagnostic ignored "-Wcast-align"
#   pragma clang diagnostic ignored "-Wextra-semi-stmt"
#   pragma clang diagnostic ignored "-Wsign-conversion"
#   pragma clang diagnostic ignored "-Wunused-function"
#   pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#   pragma clang diagnostic ignored "-Wdouble-promotion"
#   pragma clang diagnostic ignored "-Wunused-parameter"
#   pragma clang diagnostic ignored "-Wimplicit-float-conversion"
#   pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#   pragma clang diagnostic ignored "-Wtautological-pointer-compare"
#   pragma clang diagnostic ignored "-Wsign-compare"
#   pragma clang diagnostic ignored "-Wmissing-prototypes"
#   pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#   pragma clang diagnostic ignored "-Wswitch-enum"
#   pragma clang diagnostic ignored "-Wswitch"
#   pragma clang diagnostic ignored "-Wdeclaration-after-statement"
#elif defined(__IS_COMPILER_ARM_COMPILER_5__)
#   pragma diag_suppress 174,177,188,68,513,144
#endif

/*============================ MACROS ========================================*/
#undef OP_CORE
#define OP_CORE this.use_as__arm_2d_op_t.use_as__arm_2d_op_core_t

#define OPCODE this.use_as__arm_2d_op_t

#ifndef __ARM_2D_CFG_USE_IIR_BLUR_ENABLE_REVERSE_PATH__
#   define __ARM_2D_CFG_USE_IIR_BLUR_ENABLE_REVERSE_PATH__ 0
#endif
      
#define BLUR_ASM 0

/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/

enum {
    __ARM_2D_OP_IDX_USER_OPCODE_TEMPLATE = __ARM_2D_OP_IDX_USER_OP_START,

};

#define PFB 0

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ PROTOTYPES ====================================*/
extern
void __arm_2d_impl_cccn888_user_opcode_template(
                            uint32_t *__RESTRICT pTarget,
                            int16_t iTargetStride,
                            arm_2d_size_t *__RESTRICT ptCopySize,
                            arm_2d_user_opcode_template_api_params_t *ptParam);


extern 
void blur_filter_asm(uint32_t *pwPixel, 
                     const uint32_t iWidth, 
                     const int32_t inc, 
                     const uint32_t shifts);  

/*============================ LOCAL VARIABLES ===============================*/
/*============================ IMPLEMENTATION ================================*/

static uint8_t sigmadbg;

/*
 * the Frontend API
 */

ARM_NONNULL(2,4)
arm_fsm_rt_t arm_2dp_cccn888_user_opcode_template(  
                            arm_2d_user_opcode_template_descriptor_t *ptOP,
                            const arm_2d_tile_t *ptTarget,
                            const arm_2d_region_t *ptRegion,
                            const arm_2d_user_opcode_template_api_params_t *ptParams)
{
    assert(NULL != ptTarget);

    ARM_2D_IMPL(arm_2d_user_opcode_template_descriptor_t, ptOP);
    
    if (!__arm_2d_op_acquire((arm_2d_op_core_t *)ptThis)) {
        return arm_fsm_rt_on_going;
    }
    
    OP_CORE.ptOp = &ARM_2D_OP_USER_OPCODE_TEMPLATE;
    
    OPCODE.Target.ptTile = ptTarget;
    OPCODE.Target.ptRegion = ptRegion;

    this.tParams = *ptParams;

    return __arm_2d_op_invoke((arm_2d_op_core_t *)ptThis);
}


/*
 * The backend entry
 */
static
arm_fsm_rt_t __arm_2d_cccn888_sw_user_opcode_template( __arm_2d_sub_task_t *ptTask)
{
    ARM_2D_IMPL(arm_2d_user_opcode_template_descriptor_t, ptTask->ptOP);

    assert(ARM_2D_COLOUR_SZ_32BIT == OP_CORE.ptOp->Info.Colour.u3ColourSZ);

    __arm_2d_impl_cccn888_user_opcode_template( ptTask->Param.tTileProcess.pBuffer,
                                                ptTask->Param.tTileProcess.iStride,
                                                &(ptTask->Param.tTileProcess.tValidRegion.tSize),
                                                &this.tParams);

    return arm_fsm_rt_cpl;
}


/* default low level implementation */
__WEAK
void __arm_2d_impl_cccn888_user_opcode_template(
                            uint32_t *__RESTRICT pwTarget,
                            int16_t iTargetStride,
                            arm_2d_size_t *__RESTRICT ptCopySize,
                            arm_2d_user_opcode_template_api_params_t *ptParam)
{
    int_fast16_t iWidth = ptCopySize->iWidth;
    int_fast16_t iHeight = ptCopySize->iHeight;
  
    //blur_filter (pwTarget, iWidth, iHeight, iTargetStride, sigma);
    int16_t iY, iX, ibyte, ibit, ratio = 256 - ptParam->chBlurDegree;
    uint16_t accuR, accuG, accuB;
    uint8_t *pchChannel = NULL;
    
    uint32_t *pwPixel = pwTarget;

    /* rows direct path */
    for (iY = 0; iY < iHeight; iY++) {   

#if BLUR_ASM
        blur_filter_asm(pwPixel, iWidth, 1, ratio);            
#else        
        pchChannel = (unsigned char *)pwPixel;     /* read RGBA 8888  */
        accuR = *pchChannel++;
        accuG = *pchChannel++;
        accuB = *pchChannel++;

        pchChannel = (unsigned char *)pwPixel;

        for (iX = 0; iX < iWidth; iX++) {

            accuR += ((*pchChannel) - accuR) * ratio >> 8;  *pchChannel++ = accuR;
            accuG += ((*pchChannel) - accuG) * ratio >> 8;  *pchChannel++ = accuG;
            accuB += ((*pchChannel) - accuB) * ratio >> 8;  *pchChannel++ = accuB;

            pchChannel++;                  /* skip A */
        }
#endif

        pwPixel +=iTargetStride;
          
    }

#if defined(__ARM_2D_CFG_USE_IIR_BLUR_ENABLE_REVERSE_PATH__)                    \
 && __ARM_2D_CFG_USE_IIR_BLUR_ENABLE_REVERSE_PATH__
    /* rows reverse path */
    
    pwPixel = &(pwTarget[(iWidth-1) + (iHeight-1)*iTargetStride]);
    
    for (iY = iHeight-1; iY > 0; iY--) {   
        
        pchChannel = (uint8_t *)pwPixel;     /* read RGBA 8888  */
        accuR = *pchChannel++;
        accuG = *pchChannel++;
        accuB = *pchChannel++;

        pchChannel = (uint8_t *)pwPixel;

        for (iX = 0; iX < iWidth; iX++)
        {   
            accuR += ((*pchChannel) - accuR) * ratio >> 8;  *pchChannel++ = accuR;
            accuG += ((*pchChannel) - accuG) * ratio >> 8;  *pchChannel++ = accuG;
            accuB += ((*pchChannel) - accuB) * ratio >> 8;  *pchChannel++ = accuB;

            pchChannel -= 7;
        }
        
        pwPixel -=iTargetStride;
    }
#endif 

#if 1

    pwPixel = pwTarget;

    /* columns direct path */
    for (iX = 0; iX < iWidth; iX++) {     
#if BLUR_ASM
        blur_filter_asm(pwPixel, iWidth, iTargetStride, ratio);            
#else          
        pchChannel = (uint8_t *)pwPixel;     /* read RGBA 8888  */
        accuR = *pchChannel++;
        accuG = *pchChannel++;
        accuB = *pchChannel++;

        pchChannel = (uint8_t *)pwPixel++;
        
        for (iY = 0; iY < iHeight; iY++) {

            accuR += ((*pchChannel) - accuR) * ratio >> 8;  *pchChannel++ = accuR;
            accuG += ((*pchChannel) - accuG) * ratio >> 8;  *pchChannel++ = accuG;
            accuB += ((*pchChannel) - accuB) * ratio >> 8;  *pchChannel++ = accuB;

            pchChannel += (iTargetStride*4) - 3;
        }
#endif        
    }
#endif


#if defined(__ARM_2D_CFG_USE_IIR_BLUR_ENABLE_REVERSE_PATH__)                    \
 && __ARM_2D_CFG_USE_IIR_BLUR_ENABLE_REVERSE_PATH__

    pwPixel = &(pwTarget[iWidth-1 + (iHeight-1)*iTargetStride]);

    /* columns reverse path */
    for (iX = iWidth-1; iX > 0; iX--)
    {   
        pchChannel = (uint8_t *)pwPixel;     /* read RGBA 8888  */
        accuR = *pchChannel++;
        accuG = *pchChannel++;
        accuB = *pchChannel++;

        pchChannel = (uint8_t *)pwPixel--;

        for (iY = 0; iY < iHeight; iY++)
        {   
            accuR += ((*pchChannel) - accuR) * ratio >> 8;  *pchChannel++ = accuR;
            accuG += ((*pchChannel) - accuG) * ratio >> 8;  *pchChannel++ = accuG;
            accuB += ((*pchChannel) - accuB) * ratio >> 8;  *pchChannel++ = accuB;

            pchChannel -= 3 + (iTargetStride*4);
        }
    }
#endif  
}

/*
 * OPCODE Low Level Implementation Entries
 */
__WEAK
def_low_lv_io(  __ARM_2D_IO_USER_OPCODE_TEMPLATE_CCCN888,
                __arm_2d_cccn888_sw_user_opcode_template);      /* Default SW Implementation */


/*
 * OPCODE
 */
const __arm_2d_op_info_t ARM_2D_OP_USER_OPCODE_TEMPLATE = {
    .Info = {
        .Colour = {
            .chScheme   = ARM_2D_COLOUR_CCCN888,
        },
        .Param = {
            .bHasSource     = false,
            .bHasTarget     = true,
        },
        .chOpIndex      = __ARM_2D_OP_IDX_USER_OPCODE_TEMPLATE,
        
        .LowLevelIO = {
            .ptTileProcessLike = ref_low_lv_io(__ARM_2D_IO_USER_OPCODE_TEMPLATE_CCCN888),
        },
    },
};



#ifdef   __cplusplus
}
#endif