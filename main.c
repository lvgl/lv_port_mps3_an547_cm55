/****************************************************************************
*  Copyright 2021 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/

/*============================ INCLUDES ======================================*/
#include "app_cfg.h"
#include "platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

/* API to show result on LCD */
void Disp0_DrawBitmap(  int16_t x, 
                        int16_t y, 
                        int16_t width, 
                        int16_t height, 
                        const uint8_t *bitmap)
{
#if __DISP0_CFG_COLOUR_DEPTH__ == 8
    extern
    void __arm_2d_impl_gray8_to_rgb565( uint8_t *__RESTRICT pchSourceBase,
                                        int16_t iSourceStride,
                                        uint16_t *__RESTRICT phwTargetBase,
                                        int16_t iTargetStride,
                                        arm_2d_size_t *__RESTRICT ptCopySize);

    static uint16_t s_hwFrameBuffer[BENCHMARK_PFB_BLOCK_WIDTH * BENCHMARK_PFB_BLOCK_HEIGHT];
    
    arm_2d_size_t size = {
        .iWidth = width,
        .iHeight = height,
    };
    __arm_2d_impl_gray8_to_rgb565( (uint8_t *)bitmap,
                                    width,
                                    (uint16_t *)s_hwFrameBuffer,
                                    width,
                                    &size);
    GLCD_DrawBitmap(x, y, width, height, (const uint8_t *)s_hwFrameBuffer);
#elif __DISP0_CFG_COLOUR_DEPTH__ == 32
    extern
    void __arm_2d_impl_cccn888_to_rgb565(uint32_t *__RESTRICT pwSourceBase,
                                        int16_t iSourceStride,
                                        uint16_t *__RESTRICT phwTargetBase,
                                        int16_t iTargetStride,
                                        arm_2d_size_t *__RESTRICT ptCopySize);

    arm_2d_size_t size = {
        .iWidth = width,
        .iHeight = height,
    };
    __arm_2d_impl_cccn888_to_rgb565((uint32_t *)bitmap,
                                    width,
                                    (uint16_t *)bitmap,
                                    width,
                                    &size);
    GLCD_DrawBitmap(x, y, width, height, bitmap);
#else
    GLCD_DrawBitmap(x, y, width, height, bitmap);
#endif
}

void next_stage_process(int16_t iWidth, int16_t iHeight, uint8_t *pchBitmap)
{
    Disp0_DrawBitmap(0, 0, iWidth, iHeight, pchBitmap);
}


#include "arm_2d_helper.h"




extern const uint16_t c_bmpHeliumRGB565[];

const arm_2d_tile_t c_tileInput = {
    .tRegion = {
        .tSize = {
            .iWidth = 320,
            .iHeight = 256,
        },
    },
    .tInfo = {
        .bIsRoot = true,
    },
    .phwBuffer = (uint16_t*)c_bmpHeliumRGB565,
};

/*
 * NOTE: working buffer
 *       it will generate a section called ".bss.noinit.tileOutput",
 *       hence we can place it to DTCM.
 *
 */
impl_fb( tileOutput, 128, 128, uint16_t );


void process_isp_ouput_with_static_framebuffer_in_dtcm(void)
{
    arm_2d_init();

    arm_2d_region_t tFocusRegion = {
        /* focus on part of the input area (64, 64) */
        .tLocation = {
            .iX = - 64, 
            .iY = - 64,
        },
        .tSize = c_tileInput.tRegion.tSize,
    };

    /* load the input image and foucs on specific region */
    arm_2d_tile_copy_only(
        &c_tileInput,           /* input tile */
        &tileOutput,            /* output tile */
        
        &tFocusRegion);         /* focus on part of the input area */


    /* the main 2D processing */
    arm_2d_filter_iir_blur_api_params_t tParam = {
        .chBlurDegree = 200,
    };
    
    arm_2dp_filter_iir_blur(
        NULL,
        &tileOutput,            /* the target buffer */
        NULL,
        &tParam
    );

    /* comsume the process result: for example, observe it on a LCD */
    next_stage_process( tileOutput.tRegion.tSize.iWidth,
                        tileOutput.tRegion.tSize.iHeight,
                        tileOutput.pchBuffer);
}




int main(void)
{
    process_isp_ouput_with_static_framebuffer_in_dtcm();

    while(1) {
    }
}


