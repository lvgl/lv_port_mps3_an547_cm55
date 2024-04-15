// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Thermostat

#ifndef _THERMOSTAT_UI_H
#define _THERMOSTAT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

extern lv_obj_t * ui_Splash;
extern lv_obj_t * ui_HVAC;
extern lv_obj_t * ui_Header;
extern lv_obj_t * ui_Header_Date;
extern lv_obj_t * ui_Header_Time;
extern lv_obj_t * ui_Arc_Group;
extern lv_obj_t * ui_Arc1;
extern lv_obj_t * ui_Temp_Bg;
extern lv_obj_t * ui_Temp_Num_Bg;
extern lv_obj_t * ui_Label_Celsius;
extern lv_obj_t * ui_Dot1;
extern lv_obj_t * ui_Dot2;
extern lv_obj_t * ui_Dot3;
extern lv_obj_t * ui_Dot8;
extern lv_obj_t * ui_Dot9;
extern lv_obj_t * ui_Label_Temp_Max;
extern lv_obj_t * ui_Label_Temp_Min;
extern lv_obj_t * ui_Footer_Group;
extern lv_obj_t * ui_Fan_Speed_Control;
extern lv_obj_t * ui_Label_Slider_Percent;
extern lv_obj_t * ui_Panel_Dots;
extern lv_obj_t * ui_Dot4;
extern lv_obj_t * ui_Dot5;
extern lv_obj_t * ui_Dot6;
extern lv_obj_t * ui_Dot7;
extern lv_obj_t * ui_Dot10;
extern lv_obj_t * ui_Label_Slider;
extern lv_obj_t * ui_Popup;
extern lv_obj_t * ui_Label_Slider_Percent1;
extern lv_obj_t * ui_Label_Slider_Percent2;
extern lv_obj_t * ui_Panel_Menu;
extern lv_obj_t * ui_Line1;
extern lv_obj_t * ui_Line2;
extern lv_obj_t * ui_Line3;
extern lv_obj_t * ui_Settings;
extern lv_obj_t * ui_Header1;
extern lv_obj_t * ui_LAbel_Settings;
extern lv_obj_t * ui_Panel_List_Group;
extern lv_obj_t * ui_List1;
extern lv_obj_t * ui_Label_List1;
extern lv_obj_t * ui_Switch1;
extern lv_obj_t * ui_List4;
extern lv_obj_t * ui_Label_List5;
extern lv_obj_t * ui_Switch2;
extern lv_obj_t * ui_List2;
extern lv_obj_t * ui_Label_List2;
extern lv_obj_t * ui_Dropdown1;
extern lv_obj_t * ui_List3;
extern lv_obj_t * ui_Label_List3;
extern lv_obj_t * ui_Checkbox1;
extern lv_obj_t * ui_Checkbox2;
extern lv_obj_t * ui_Checkbox3;
extern lv_obj_t * ui_Group_Roller;
extern lv_obj_t * ui_Label_List4;
extern lv_obj_t * ui_Roller1;
extern lv_obj_t * ui_Panel_Menu1;
extern lv_obj_t * ui_ALbel_Back;

void toast_anim_start(lv_event_t * e);
void fan_speed_value(lv_event_t * e);



LV_FONT_DECLARE(ui_font_Number);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
