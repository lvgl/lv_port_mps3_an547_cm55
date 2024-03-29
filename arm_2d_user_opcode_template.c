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
#define OP_CORE this.use_as__arm_2d_op_cp_t.use_as__arm_2d_op_core_t

#define OPCODE this.use_as__arm_2d_op_cp_t

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
                            uint32_t *__RESTRICT pSource,
                            int16_t iSourceStride,
                            uint32_t *__RESTRICT pTarget,
                            int16_t iTargetStride,
                            arm_2d_size_t *__RESTRICT ptCopySize,
                            arm_2d_user_opcode_template_api_params_t *ptParam);

/*============================ LOCAL VARIABLES ===============================*/
/*============================ IMPLEMENTATION ================================*/

/*
 * the Frontend API
 */

ARM_NONNULL(2,3,5)
arm_fsm_rt_t arm_2dp_cccn888_user_opcode_template(  
                            arm_2d_user_opcode_template_descriptor_t *ptOP,
                            const arm_2d_tile_t *ptSource,
                            const arm_2d_tile_t *ptTarget,
                            const arm_2d_region_t *ptRegion,
                            const arm_2d_user_opcode_template_api_params_t *ptParams)
{

    assert(NULL != ptSource);
    assert(NULL != ptTarget);

    ARM_2D_IMPL(arm_2d_user_opcode_template_descriptor_t, ptOP);
    
    if (!__arm_2d_op_acquire((arm_2d_op_core_t *)ptThis)) {
        return arm_fsm_rt_on_going;
    }
    
    OP_CORE.ptOp = &ARM_2D_OP_USER_OPCODE_TEMPLATE;
    
    OPCODE.Target.ptTile = ptTarget;
    OPCODE.Target.ptRegion = ptRegion;
    OPCODE.Source.ptTile = ptSource;
    OPCODE.wMode = 0;

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

    //ptTask->Param.tCopy.tTarget.tValidRegion.tLocation.iX
    __arm_2d_impl_cccn888_user_opcode_template( ptTask->Param.tCopy.tSource.pBuffer,
                                                ptTask->Param.tCopy.tSource.iStride,
                                                ptTask->Param.tCopy.tTarget.pBuffer,
                                                ptTask->Param.tCopy.tTarget.iStride,
                                                &ptTask->Param.tCopy.tCopySize,
                                                &this.tParams);

    return arm_fsm_rt_cpl;
}

#define PFB_BLUR 0

               
void blur_filter (uint32_t * data, short iWidth, short iHeight, short iTargetStride, char c)           
{
    short iY, iX, k;
    unsigned short accuR, accuG, accuB;
    unsigned char *pt8;
    uint32_t *pt32;

    pt32 = data;

    /* rows direct path */
    for (iY = 0; iY < iHeight; iY++) {   

        pt8 = (unsigned char *)pt32;     /* read RGBA 8888  */
        accuR = *pt8++;
        accuG = *pt8++;
        accuB = *pt8++;
        //pt8++;                  /* skip A */
        pt8 = (unsigned char *)pt32;

        for (iX = 0; iX < iWidth; iX++)
        {
            accuR += ((*pt8) - accuR) >> c;  *pt8++ = accuR;
            accuG += ((*pt8) - accuG) >> c;  *pt8++ = accuG;
            accuB += ((*pt8) - accuB) >> c;  *pt8++ = accuB;
            pt8++;                  /* skip A */
        }
        
        pt32 +=iTargetStride;
          
    }

#if 0
    /* rows reverse path */
    for (iY = iHeight-1; iY > 0; iY--)
    {   
        pt32 = &(data[iWidth-1 + iY*iTargetStride]);
        pt8 = (char *)pt32;     /* read RGBA 8888  */
        accuR = *pt8++;
        accuG = *pt8++;
        accuB = *pt8++;
        pt8++;                  /* skip A */
        pt8 = pt8-4;   

        for (iX = 0; iX < iWidth; iX++)
        {   
            accuR += ((*pt8) - accuR) >> c;  *pt8++ = accuR;
            accuG += ((*pt8) - accuG) >> c;  *pt8++ = accuG;
            accuB += ((*pt8) - accuB) >> c;  *pt8++ = accuB;
            pt8++; 
            pt8 = pt8 - 8;
        }
    }
#endif 

#if 1

    pt32 = data;

    /* columns direct path */
    for (iX = 0; iX < iWidth; iX++)
    {     
        pt8 = (uint8_t *)pt32;     /* read RGBA 8888  */
        accuR = *pt8++;
        accuG = *pt8++;
        accuB = *pt8++;

        pt8 = (uint8_t *)pt32++;
        
        for (iY = 0; iY < iHeight; iY++) {
            accuR += ((*pt8) - accuR) >> c;  *pt8++ = accuR;
            accuG += ((*pt8) - accuG) >> c;  *pt8++ = accuG;
            accuB += ((*pt8) - accuB) >> c;  *pt8++ = accuB;

            pt8 += (iTargetStride*4) - 3;
        }
    }
#endif
#if 0
    /* columns reverse path */
    for (iX = iWidth-1; iX > 0; iX--)
    {   
        pt32 = &(data[iX + (iHeight-1)*iTargetStride]);
        pt8 = (char *)pt32;     /* read RGBA 8888  */
        accuR = *pt8++;
        accuG = *pt8++;
        accuB = *pt8++;
        pt8++;                  /* skip A */
        pt8 = pt8-4;   

        for (iY = 0; iY < iHeight; iY++)
        {   
            accuR += ((*pt8) - accuR) >> c;  *pt8++ = accuR;
            accuG += ((*pt8) - accuG) >> c;  *pt8++ = accuG;
            accuB += ((*pt8) - accuB) >> c;  *pt8++ = accuB;
            pt8++; 
            pt8 = pt8 - 4 - (iTargetStride*4);
        }
    }
#endif    
}

/* default low level implementation */
__WEAK
void __arm_2d_impl_cccn888_user_opcode_template(
                                    uint32_t *__RESTRICT pwSource,
                                    int16_t iSourceStride,
                                    uint32_t *__RESTRICT pwTarget,
                                    int16_t iTargetStride,
                                    arm_2d_size_t *__RESTRICT ptCopySize,
                                    arm_2d_user_opcode_template_api_params_t *ptParam)
{
    int_fast16_t iWidth = ptCopySize->iWidth;
    int_fast16_t iHeight = ptCopySize->iHeight;

    uint_fast8_t chTargetChannel = ptParam->chChannel;
    uint_fast8_t sigma = ptParam->sigma;

  
    blur_filter (pwTarget, iWidth, iHeight, iTargetStride, sigma);


#if 0
    for (int_fast16_t iY = 0; iY < ptCopySize->iHeight; iY++) {

        uint32_t *pwSourceLine = pwSource;
        uint32_t *pwTargetLine = pwTarget;

        for (int_fast16_t iX = 0; iX < iWidth; iX++) {

            arm_2d_color_ccca8888_t tSourcePixel = {.tValue = *pwSourceLine++};
            arm_2d_color_ccca8888_t tTargetPixel = {0};

            tTargetPixel.u8C[chTargetChannel] = tSourcePixel.u8C[chTargetChannel];  // @@@@@@ 

            *pwTargetLine++ = tTargetPixel.tValue;

        }

        pwSource += iSourceStride;
        pwTarget += iTargetStride;
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
            .bHasSource     = true,
            .bHasTarget     = true,
        },
        .chOpIndex      = __ARM_2D_OP_IDX_USER_OPCODE_TEMPLATE,
        
        .LowLevelIO = {
            .ptCopyLike = ref_low_lv_io(__ARM_2D_IO_USER_OPCODE_TEMPLATE_CCCN888),
            .ptFillLike = NULL,
        },
    },
};



#ifdef   __cplusplus
}
#endif

