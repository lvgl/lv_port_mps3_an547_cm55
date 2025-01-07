/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"

#include "Board_GLCD.h"
#include "GLCD_Config.h"
#include "perf_counter.h"

#if defined(__RTE_ACCELERATION_ARM_2D__)
//#include "lv_gpu_arm2d.h"
#include "arm_2d.h"
#endif
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*------------------------------------
     * Create a display and set a flush_cb
     * -----------------------------------*/
    lv_display_t * disp = lv_display_create(GLCD_WIDTH, GLCD_HEIGHT);
    lv_display_set_flush_cb(disp, disp_flush);
    
    /* Example 1
     * One buffer for partial rendering*/
#if LV_COLOR_DEPTH == 32
    static lv_color_t buf_1[GLCD_WIDTH * GLCD_HEIGHT / 10];
#else
    static lv_color_t buf_1[GLCD_WIDTH * (GLCD_HEIGHT / 4) ];
#endif
    lv_display_set_buffers(disp, buf_1, NULL, sizeof(buf_1), LV_DISPLAY_RENDER_MODE_PARTIAL);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    /*You code here*/
}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
#if !defined(__USE_FVP__)
    if (disp_flush_enabled) {
#endif
        do {
            lv_color_format_t color_format = lv_display_get_color_format(disp_drv);
            int32_t width = area->x2 - area->x1 + 1;
            int32_t height = area->y2 - area->y1 + 1;
            int32_t stride = lv_draw_buf_width_to_stride( width, color_format);
            width *= lv_color_format_get_bpp(color_format) >> 3;
            
            if (width == stride) {
                break;
            }
            
            uint8_t *src_ptr = px_map;
            uint8_t *des_ptr = px_map;
             
            for (int y = 0; y < height; y++) {
                lv_memcpy(des_ptr, src_ptr, width);
                
                src_ptr += stride;
                des_ptr += width;
            }
        } while(0);

    #if defined(__RTE_ACCELERATION_ARM_2D__)
        extern
        void __arm_2d_impl_cccn888_to_rgb565(uint32_t *__RESTRICT pwSourceBase,
                                            int16_t iSourceStride,
                                            uint16_t *__RESTRICT phwTargetBase,
                                            int16_t iTargetStride,
                                            arm_2d_size_t *__RESTRICT ptCopySize);

    #if LV_COLOR_DEPTH == 32
        arm_2d_size_t size = {
            .iWidth = area->x2 - area->x1 + 1,
            .iHeight = area->y2 - area->y1 + 1,
        };
        __arm_2d_impl_cccn888_to_rgb565((uint32_t *)px_map,
                                        size.iWidth,
                                        (uint16_t *)px_map,
                                        size.iWidth,
                                        &size);
    #endif
    #endif

        GLCD_DrawBitmap(area->x1,               //!< x
                        area->y1,               //!< y
                        area->x2 - area->x1 + 1,    //!< width
                        area->y2 - area->y1 + 1,    //!< height
                        (const uint8_t *)px_map);
#if !defined(__USE_FVP__)
    }
#endif

    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_display_flush_ready(disp_drv);
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
