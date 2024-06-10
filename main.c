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

#if defined(RTE_Acceleration_Arm_2D)
#   include "arm_2d.h"
#endif

#if defined(RTE_Acceleration_Arm_2D_Helper_PFB)
#   include "arm_2d_helper.h"
#   include "arm_2d_disp_adapters.h"
#   include "arm_2d_scenes.h"
#   include "arm_2d_scene_alarm_clock.h"
#   include "arm_2d_scene_atom.h"
#endif




/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

#if defined(RTE_Acceleration_Arm_2D_Helper_Disp_Adapter0)


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



int main(void)
{
    arm_2d_init();
    
    disp_adapter0_init();
    
//arm_2d_scene_atom_init(&DISP0_ADAPTER);
    arm_2d_scene0_init(&DISP0_ADAPTER);
    arm_2d_scene_player_set_switching_mode(&DISP0_ADAPTER,
                                           ARM_2D_SCENE_SWITCH_MODE_FADE_WHITE);
    arm_2d_scene_player_set_switching_period(&DISP0_ADAPTER, 3000);
    arm_2d_scene_player_switch_to_next_scene(&DISP0_ADAPTER);

    while(1) {
        disp_adapter0_task();
    }
}


#else

int main(void)
{
    printf("Hello LVGL!!\r\n");
    
    __cycleof__("Draw strings on LCD") {
        __LL_LCD_PRINT_BANNER("Hello LVGL!!");
    }
    
    while(1) {
    
    }
    
}

#endif
