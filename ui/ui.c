// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Thermostat

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Splash;
lv_obj_t * ui_HVAC;
lv_obj_t * ui_Header;
lv_obj_t * ui_Header_Date;
lv_obj_t * ui_Header_Time;
lv_obj_t * ui_Arc_Group;
lv_obj_t * ui_Arc1;
lv_obj_t * ui_Temp_Bg;
lv_obj_t * ui_Temp_Num_Bg;
lv_obj_t * ui_Label_Celsius;
lv_obj_t * ui_Dot1;
lv_obj_t * ui_Dot2;
lv_obj_t * ui_Dot3;
lv_obj_t * ui_Dot8;
lv_obj_t * ui_Dot9;
lv_obj_t * ui_Label_Temp_Max;
lv_obj_t * ui_Label_Temp_Min;
lv_obj_t * ui_Footer_Group;
lv_obj_t * ui_Fan_Speed_Control;
lv_obj_t * ui_Label_Slider_Percent;
lv_obj_t * ui_Panel_Dots;
lv_obj_t * ui_Dot4;
lv_obj_t * ui_Dot5;
lv_obj_t * ui_Dot6;
lv_obj_t * ui_Dot7;
lv_obj_t * ui_Dot10;
lv_obj_t * ui_Label_Slider;
lv_obj_t * ui_Popup;
lv_obj_t * ui_Label_Slider_Percent1;
lv_obj_t * ui_Label_Slider_Percent2;
lv_obj_t * ui_Panel_Menu;
lv_obj_t * ui_Line1;
lv_obj_t * ui_Line2;
lv_obj_t * ui_Line3;
lv_obj_t * ui_Settings;
lv_obj_t * ui_Header1;
lv_obj_t * ui_LAbel_Settings;
lv_obj_t * ui_Panel_List_Group;
lv_obj_t * ui_List1;
lv_obj_t * ui_Label_List1;
lv_obj_t * ui_Switch1;
lv_obj_t * ui_List4;
lv_obj_t * ui_Label_List5;
lv_obj_t * ui_Switch2;
lv_obj_t * ui_List2;
lv_obj_t * ui_Label_List2;
lv_obj_t * ui_Dropdown1;
lv_obj_t * ui_List3;
lv_obj_t * ui_Label_List3;
lv_obj_t * ui_Checkbox1;
lv_obj_t * ui_Checkbox2;
lv_obj_t * ui_Checkbox3;
lv_obj_t * ui_Group_Roller;
lv_obj_t * ui_Label_List4;
lv_obj_t * ui_Roller1;
lv_obj_t * ui_Panel_Menu1;
lv_obj_t * ui_ALbel_Back;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

// ui_EloAnimation0
// FUNCTION HEADER
void Up_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void Up_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 150);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);

    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);

    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

    //
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 300);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_1, 50, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);

    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);

    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}

// ui_EloAnimation0
// FUNCTION HEADER
void Down_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void Down_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 150);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);

    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);

    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

    //
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 300);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_1, -50, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);

    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);

    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}

// ui_EloAnimation0
// FUNCTION HEADER
void Popup_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void Popup_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);

    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);

    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

    //
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 500);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_1, -50, -9);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);

    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);

    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

    //
    lv_anim_t PropertyAnimation_2;
    lv_anim_init(&PropertyAnimation_2);
    lv_anim_set_time(&PropertyAnimation_2, 500);
    lv_anim_set_user_data(&PropertyAnimation_2, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_2, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_2, -9, -100);
    lv_anim_set_path_cb(&PropertyAnimation_2, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_2, delay + 4000);

    lv_anim_set_playback_time(&PropertyAnimation_2, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_2, 0);

    lv_anim_set_early_apply(&PropertyAnimation_2, false);
    lv_anim_start(&PropertyAnimation_2);

    //
    lv_anim_t PropertyAnimation_3;
    lv_anim_init(&PropertyAnimation_3);
    lv_anim_set_time(&PropertyAnimation_3, 500);
    lv_anim_set_user_data(&PropertyAnimation_3, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_3, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_3, 255, 0);
    lv_anim_set_path_cb(&PropertyAnimation_3, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_3, delay + 4000);

    lv_anim_set_playback_time(&PropertyAnimation_3, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_3, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_3, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_3, 0);

    lv_anim_set_early_apply(&PropertyAnimation_3, false);
    lv_anim_start(&PropertyAnimation_3);

}

///////////////////// FUNCTIONS ////////////////////
static void ui_event_Splash(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(ui_HVAC, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0);
        toast_anim_start(e);
    }
}
static void ui_event_HVAC(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOAD_START) {
        Up_Animation(ui_Footer_Group, 200);
        Down_Animation(ui_Arc_Group, 200);
    }
}
static void ui_event_Arc1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_Label_Celsius, ta, "", "°");
    }
}
static void ui_event_Fan_Speed_Control(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        fan_speed_value(e);
    }
}
static void ui_event_Panel_Menu(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 0);
    }
}
static void ui_event_Panel_Menu1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_HVAC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Splash_screen_init(void)
{

    // ui_Splash

    ui_Splash = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Splash, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Splash, ui_event_Splash, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_Splash, lv_color_hex(0x10151D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Splash, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_HVAC_screen_init(void)
{

    // ui_HVAC

    ui_HVAC = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_HVAC, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_HVAC, ui_event_HVAC, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_HVAC, lv_color_hex(0x606672), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HVAC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_HVAC, lv_color_hex(0x33363E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_HVAC, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Header

    ui_Header = lv_obj_create(ui_HVAC);

    lv_obj_set_height(ui_Header, 32);
    lv_obj_set_width(ui_Header, lv_pct(100));

    lv_obj_set_x(ui_Header, 0);
    lv_obj_set_y(ui_Header, 0);

    lv_obj_clear_flag(ui_Header, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Header, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Header_Date

    ui_Header_Date = lv_label_create(ui_Header);

    lv_obj_set_width(ui_Header_Date, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Header_Date, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Header_Date, 0);
    lv_obj_set_y(ui_Header_Date, 0);

    lv_obj_set_align(ui_Header_Date, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Header_Date, "Friday, March 11, 2022");

    lv_obj_set_style_text_color(ui_Header_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Header_Date, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Header_Time

    ui_Header_Time = lv_label_create(ui_Header);

    lv_obj_set_width(ui_Header_Time, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Header_Time, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Header_Time, -65);
    lv_obj_set_y(ui_Header_Time, 1);

    lv_obj_set_align(ui_Header_Time, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_Header_Time, "AM 7:45");

    lv_obj_set_style_text_color(ui_Header_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Header_Time, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Arc_Group

    ui_Arc_Group = lv_obj_create(ui_HVAC);

    lv_obj_set_width(ui_Arc_Group, 252);
    lv_obj_set_height(ui_Arc_Group, 239);

    lv_obj_set_x(ui_Arc_Group, 0);
    lv_obj_set_y(ui_Arc_Group, 16);

    lv_obj_set_align(ui_Arc_Group, LV_ALIGN_LEFT_MID);

    lv_obj_clear_flag(ui_Arc_Group, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Arc_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Arc_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Arc1

    ui_Arc1 = lv_arc_create(ui_Arc_Group);

    lv_obj_set_width(ui_Arc1, 175);
    lv_obj_set_height(ui_Arc1, 175);

    lv_obj_set_x(ui_Arc1, 0);
    lv_obj_set_y(ui_Arc1, 0);

    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);

    lv_arc_set_range(ui_Arc1, 15, 35);
    lv_arc_set_value(ui_Arc1, 23);
    lv_arc_set_bg_angles(ui_Arc1, 120, 60);

    lv_obj_add_event_cb(ui_Arc1, ui_event_Arc1, LV_EVENT_ALL, NULL);

    lv_obj_set_style_radius(ui_Arc1, 350, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Arc1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Arc1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Arc1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Arc1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x0398FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Temp_Bg

    ui_Temp_Bg = lv_obj_create(ui_Arc_Group);

    lv_obj_set_width(ui_Temp_Bg, 145);
    lv_obj_set_height(ui_Temp_Bg, 145);

    lv_obj_set_x(ui_Temp_Bg, 0);
    lv_obj_set_y(ui_Temp_Bg, 0);

    lv_obj_set_align(ui_Temp_Bg, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Temp_Bg, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Temp_Bg, 280, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Temp_Bg, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Temp_Bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Temp_Bg, lv_color_hex(0x3C414B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Temp_Bg, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Temp_Bg, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Temp_Bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Temp_Bg, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Temp_Bg, lv_color_hex(0x050A0F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Temp_Bg, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Temp_Bg, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Temp_Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Temp_Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Temp_Bg, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Temp_Num_Bg

    ui_Temp_Num_Bg = lv_obj_create(ui_Temp_Bg);

    lv_obj_set_width(ui_Temp_Num_Bg, 100);
    lv_obj_set_height(ui_Temp_Num_Bg, 100);

    lv_obj_set_x(ui_Temp_Num_Bg, 0);
    lv_obj_set_y(ui_Temp_Num_Bg, 0);

    lv_obj_set_align(ui_Temp_Num_Bg, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Temp_Num_Bg, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Temp_Num_Bg, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Temp_Num_Bg, lv_color_hex(0x0C191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Temp_Num_Bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Temp_Num_Bg, lv_color_hex(0x191C26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Temp_Num_Bg, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Temp_Num_Bg, lv_color_hex(0x5A646E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Temp_Num_Bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Temp_Num_Bg, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Celsius

    ui_Label_Celsius = lv_label_create(ui_Temp_Num_Bg);

    lv_obj_set_width(ui_Label_Celsius, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_Celsius, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Celsius, 10);
    lv_obj_set_y(ui_Label_Celsius, 1);

    lv_obj_set_align(ui_Label_Celsius, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label_Celsius, "23°");

    lv_obj_set_style_text_color(ui_Label_Celsius, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Celsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Celsius, &ui_font_Number, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot1

    ui_Dot1 = lv_obj_create(ui_Arc_Group);

    lv_obj_set_width(ui_Dot1, 3);
    lv_obj_set_height(ui_Dot1, 3);

    lv_obj_set_x(ui_Dot1, 45);
    lv_obj_set_y(ui_Dot1, -30);

    lv_obj_set_align(ui_Dot1, LV_ALIGN_BOTTOM_LEFT);

    lv_obj_clear_flag(ui_Dot1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot2

    ui_Dot2 = lv_obj_create(ui_Arc_Group);

    lv_obj_set_width(ui_Dot2, 3);
    lv_obj_set_height(ui_Dot2, 3);

    lv_obj_set_x(ui_Dot2, -45);
    lv_obj_set_y(ui_Dot2, -30);

    lv_obj_set_align(ui_Dot2, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_clear_flag(ui_Dot2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot3

    ui_Dot3 = lv_obj_create(ui_Arc_Group);

    lv_obj_set_width(ui_Dot3, 5);
    lv_obj_set_height(ui_Dot3, 5);

    lv_obj_set_x(ui_Dot3, 0);
    lv_obj_set_y(ui_Dot3, 8);

    lv_obj_set_align(ui_Dot3, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Dot3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot8

    ui_Dot8 = lv_obj_create(ui_Arc_Group);

    lv_obj_set_width(ui_Dot8, 3);
    lv_obj_set_height(ui_Dot8, 3);

    lv_obj_set_x(ui_Dot8, 93);
    lv_obj_set_y(ui_Dot8, -23);

    lv_obj_set_align(ui_Dot8, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Dot8, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot9

    ui_Dot9 = lv_obj_create(ui_Arc_Group);

    lv_obj_set_width(ui_Dot9, 3);
    lv_obj_set_height(ui_Dot9, 3);

    lv_obj_set_x(ui_Dot9, -93);
    lv_obj_set_y(ui_Dot9, -23);

    lv_obj_set_align(ui_Dot9, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Dot9, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Temp_Max

    ui_Label_Temp_Max = lv_label_create(ui_Arc_Group);

    lv_obj_set_width(ui_Label_Temp_Max, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_Temp_Max, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Temp_Max, 67);
    lv_obj_set_y(ui_Label_Temp_Max, 190);

    lv_obj_set_align(ui_Label_Temp_Max, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_Label_Temp_Max, "35°");

    lv_obj_set_style_text_color(ui_Label_Temp_Max, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Temp_Max, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Temp_Max, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Temp_Max, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Temp_Min

    ui_Label_Temp_Min = lv_label_create(ui_Arc_Group);

    lv_obj_set_width(ui_Label_Temp_Min, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_Temp_Min, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Temp_Min, -66);
    lv_obj_set_y(ui_Label_Temp_Min, 189);

    lv_obj_set_align(ui_Label_Temp_Min, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_Label_Temp_Min, "15°");

    lv_obj_set_style_text_color(ui_Label_Temp_Min, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Temp_Min, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Temp_Min, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Temp_Min, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Footer_Group

    ui_Footer_Group = lv_obj_create(ui_HVAC);

    lv_obj_set_width(ui_Footer_Group, 70);
    lv_obj_set_height(ui_Footer_Group, 208);

    lv_obj_set_x(ui_Footer_Group, 0);
    lv_obj_set_y(ui_Footer_Group, 0);

    lv_obj_set_align(ui_Footer_Group, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_clear_flag(ui_Footer_Group, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Footer_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Footer_Group, lv_color_hex(0x202831), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Footer_Group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Footer_Group, lv_color_hex(0x101215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Footer_Group, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Footer_Group, lv_color_hex(0x5A606B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Footer_Group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Footer_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Footer_Group, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Footer_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Footer_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Footer_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Footer_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Fan_Speed_Control

    ui_Fan_Speed_Control = lv_slider_create(ui_Footer_Group);
    lv_slider_set_range(ui_Fan_Speed_Control, 0, 4);
    lv_slider_set_value(ui_Fan_Speed_Control, 2, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Fan_Speed_Control) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Fan_Speed_Control, 0,
                                                                                                      LV_ANIM_OFF);

    lv_obj_set_width(ui_Fan_Speed_Control, 11);
    lv_obj_set_height(ui_Fan_Speed_Control, 117);

    lv_obj_set_x(ui_Fan_Speed_Control, -17);
    lv_obj_set_y(ui_Fan_Speed_Control, 19);

    lv_obj_set_align(ui_Fan_Speed_Control, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Fan_Speed_Control, ui_event_Fan_Speed_Control, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Fan_Speed_Control, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Fan_Speed_Control, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Fan_Speed_Control, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Fan_Speed_Control, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x37B9F5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Fan_Speed_Control, lv_color_hex(0x1464F0), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Fan_Speed_Control, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x5F6464), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Fan_Speed_Control, lv_color_hex(0x3C424B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Fan_Speed_Control, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Fan_Speed_Control, lv_color_hex(0x2FA5F3), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Fan_Speed_Control, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Fan_Speed_Control, lv_color_hex(0x1E232D), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Fan_Speed_Control, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Fan_Speed_Control, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Fan_Speed_Control, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Fan_Speed_Control, 150, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Fan_Speed_Control, 20, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Fan_Speed_Control, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Fan_Speed_Control, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Fan_Speed_Control, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Fan_Speed_Control, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Fan_Speed_Control, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x3EB0FF), LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui_Fan_Speed_Control, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_Fan_Speed_Control, lv_color_hex(0x0096FF), LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_Fan_Speed_Control, 4, LV_PART_KNOB | LV_STATE_PRESSED);

    // ui_Label_Slider_Percent

    ui_Label_Slider_Percent = lv_label_create(ui_Footer_Group);

    lv_obj_set_width(ui_Label_Slider_Percent, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_Slider_Percent, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Slider_Percent, 17);
    lv_obj_set_y(ui_Label_Slider_Percent, 56);

    lv_obj_set_align(ui_Label_Slider_Percent, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_Label_Slider_Percent, "4\n\n3\n\n2\n\n1\n\nOff");

    lv_obj_set_style_text_color(ui_Label_Slider_Percent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Slider_Percent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Slider_Percent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Slider_Percent, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel_Dots

    ui_Panel_Dots = lv_obj_create(ui_Footer_Group);

    lv_obj_set_width(ui_Panel_Dots, 20);
    lv_obj_set_height(ui_Panel_Dots, 135);

    lv_obj_set_x(ui_Panel_Dots, 7);
    lv_obj_set_y(ui_Panel_Dots, 19);

    lv_obj_set_align(ui_Panel_Dots, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel_Dots, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Panel_Dots, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Dots, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_Dots, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel_Dots, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel_Dots, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel_Dots, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel_Dots, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot4

    ui_Dot4 = lv_obj_create(ui_Panel_Dots);

    lv_obj_set_width(ui_Dot4, 3);
    lv_obj_set_height(ui_Dot4, 3);

    lv_obj_set_x(ui_Dot4, -4);
    lv_obj_set_y(ui_Dot4, 7);

    lv_obj_set_align(ui_Dot4, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Dot4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot4, lv_color_hex(0x8D97A8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot5

    ui_Dot5 = lv_obj_create(ui_Panel_Dots);

    lv_obj_set_width(ui_Dot5, 3);
    lv_obj_set_height(ui_Dot5, 3);

    lv_obj_set_x(ui_Dot5, -4);
    lv_obj_set_y(ui_Dot5, 36);

    lv_obj_set_align(ui_Dot5, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Dot5, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot5, lv_color_hex(0x8D97A8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot6

    ui_Dot6 = lv_obj_create(ui_Panel_Dots);

    lv_obj_set_width(ui_Dot6, 3);
    lv_obj_set_height(ui_Dot6, 3);

    lv_obj_set_x(ui_Dot6, -4);
    lv_obj_set_y(ui_Dot6, 66);

    lv_obj_set_align(ui_Dot6, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Dot6, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot6, lv_color_hex(0x8D97A8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot7

    ui_Dot7 = lv_obj_create(ui_Panel_Dots);

    lv_obj_set_width(ui_Dot7, 3);
    lv_obj_set_height(ui_Dot7, 3);

    lv_obj_set_x(ui_Dot7, -4);
    lv_obj_set_y(ui_Dot7, 96);

    lv_obj_set_align(ui_Dot7, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Dot7, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot7, lv_color_hex(0x8D97A8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dot10

    ui_Dot10 = lv_obj_create(ui_Panel_Dots);

    lv_obj_set_width(ui_Dot10, 3);
    lv_obj_set_height(ui_Dot10, 3);

    lv_obj_set_x(ui_Dot10, -4);
    lv_obj_set_y(ui_Dot10, 126);

    lv_obj_set_align(ui_Dot10, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Dot10, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Dot10, lv_color_hex(0x8D97A8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dot10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dot10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Slider

    ui_Label_Slider = lv_label_create(ui_Footer_Group);

    lv_obj_set_width(ui_Label_Slider, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_Slider, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Slider, 0);
    lv_obj_set_y(ui_Label_Slider, 11);

    lv_obj_set_align(ui_Label_Slider, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_Label_Slider, "Fan\nSpeed");

    lv_obj_set_style_text_color(ui_Label_Slider, lv_color_hex(0x8D97A8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Slider, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Slider, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Popup

    ui_Popup = lv_obj_create(ui_HVAC);

    lv_obj_set_width(ui_Popup, 221);
    lv_obj_set_height(ui_Popup, 124);

    lv_obj_set_x(ui_Popup, 0);
    lv_obj_set_y(ui_Popup, -8);

    lv_obj_set_align(ui_Popup, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Popup, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Popup, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Popup, lv_color_hex(0x24282E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Popup, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Popup, lv_color_hex(0x2FA5EA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Popup, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Popup, lv_color_hex(0x2DA1E8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Popup, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Popup, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Popup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Popup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Popup, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Popup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Popup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Popup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Popup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Popup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Slider_Percent1

    ui_Label_Slider_Percent1 = lv_label_create(ui_Popup);

    lv_obj_set_width(ui_Label_Slider_Percent1, lv_pct(92));
    lv_obj_set_height(ui_Label_Slider_Percent1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Slider_Percent1, 0);
    lv_obj_set_y(ui_Label_Slider_Percent1, 16);

    lv_obj_set_align(ui_Label_Slider_Percent1, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_Label_Slider_Percent1, "No images are used\nin this UI.");

    lv_obj_set_style_text_color(ui_Label_Slider_Percent1, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Slider_Percent1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label_Slider_Percent1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label_Slider_Percent1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Slider_Percent1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Slider_Percent1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Label_Slider_Percent1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_Slider_Percent1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_Slider_Percent1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label_Slider_Percent1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label_Slider_Percent1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label_Slider_Percent1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label_Slider_Percent1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Slider_Percent2

    ui_Label_Slider_Percent2 = lv_label_create(ui_Popup);

    lv_obj_set_width(ui_Label_Slider_Percent2, lv_pct(101));
    lv_obj_set_height(ui_Label_Slider_Percent2, lv_pct(32));

    lv_obj_set_x(ui_Label_Slider_Percent2, 0);
    lv_obj_set_y(ui_Label_Slider_Percent2, -5);

    lv_obj_set_align(ui_Label_Slider_Percent2, LV_ALIGN_BOTTOM_MID);

    lv_label_set_text(ui_Label_Slider_Percent2, "All shapes are rendered\nby LVGL dynamically.");

    lv_obj_set_style_text_color(ui_Label_Slider_Percent2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Slider_Percent2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label_Slider_Percent2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label_Slider_Percent2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Slider_Percent2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Slider_Percent2, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel_Menu

    ui_Panel_Menu = lv_obj_create(ui_HVAC);

    lv_obj_set_width(ui_Panel_Menu, 70);
    lv_obj_set_height(ui_Panel_Menu, 32);

    lv_obj_set_x(ui_Panel_Menu, 0);
    lv_obj_set_y(ui_Panel_Menu, 0);

    lv_obj_set_align(ui_Panel_Menu, LV_ALIGN_TOP_RIGHT);

    lv_obj_clear_flag(ui_Panel_Menu, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Panel_Menu, ui_event_Panel_Menu, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_Panel_Menu, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel_Menu, lv_color_hex(0x35B5F0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Menu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel_Menu, lv_color_hex(0x5A606B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel_Menu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_Menu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Panel_Menu, lv_color_hex(0x12B0FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_opa(ui_Panel_Menu, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_width(ui_Panel_Menu, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_pad(ui_Panel_Menu, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Panel_Menu, lv_color_hex(0x32AFED), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Panel_Menu, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Panel_Menu, 80, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Panel_Menu, 4, LV_PART_MAIN | LV_STATE_PRESSED);

    // ui_Line1

    ui_Line1 = lv_obj_create(ui_Panel_Menu);

    lv_obj_set_width(ui_Line1, 20);
    lv_obj_set_height(ui_Line1, 2);

    lv_obj_set_x(ui_Line1, 0);
    lv_obj_set_y(ui_Line1, 0);

    lv_obj_set_align(ui_Line1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Line1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Line1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Line1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Line1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Line2

    ui_Line2 = lv_obj_create(ui_Panel_Menu);

    lv_obj_set_width(ui_Line2, 20);
    lv_obj_set_height(ui_Line2, 2);

    lv_obj_set_x(ui_Line2, 0);
    lv_obj_set_y(ui_Line2, 7);

    lv_obj_set_align(ui_Line2, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Line2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_border_width(ui_Line2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Line3

    ui_Line3 = lv_obj_create(ui_Panel_Menu);

    lv_obj_set_width(ui_Line3, 20);
    lv_obj_set_height(ui_Line3, 2);

    lv_obj_set_x(ui_Line3, 0);
    lv_obj_set_y(ui_Line3, -7);

    lv_obj_set_align(ui_Line3, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Line3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_border_width(ui_Line3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_Settings_screen_init(void)
{

    // ui_Settings

    ui_Settings = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Settings, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Settings, lv_color_hex(0x282C33), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Settings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Settings, lv_color_hex(0x121518), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Settings, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Header1

    ui_Header1 = lv_obj_create(ui_Settings);

    lv_obj_set_height(ui_Header1, 32);
    lv_obj_set_width(ui_Header1, lv_pct(100));

    lv_obj_set_x(ui_Header1, 0);
    lv_obj_set_y(ui_Header1, 0);

    lv_obj_set_align(ui_Header1, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Header1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Header1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Header1, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Header1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LAbel_Settings

    ui_LAbel_Settings = lv_label_create(ui_Header1);

    lv_obj_set_width(ui_LAbel_Settings, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LAbel_Settings, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LAbel_Settings, 0);
    lv_obj_set_y(ui_LAbel_Settings, 0);

    lv_obj_set_align(ui_LAbel_Settings, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_LAbel_Settings, "Settings");

    lv_obj_set_style_text_color(ui_LAbel_Settings, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LAbel_Settings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LAbel_Settings, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel_List_Group

    ui_Panel_List_Group = lv_obj_create(ui_Settings);

    lv_obj_set_height(ui_Panel_List_Group, 207);
    lv_obj_set_width(ui_Panel_List_Group, lv_pct(100));

    lv_obj_set_x(ui_Panel_List_Group, 1);
    lv_obj_set_y(ui_Panel_List_Group, 32);

    lv_obj_set_align(ui_Panel_List_Group, LV_ALIGN_TOP_MID);

    lv_obj_set_scroll_dir(ui_Panel_List_Group, LV_DIR_VER);

    lv_obj_set_style_radius(ui_Panel_List_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel_List_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_List_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_List_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel_List_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel_List_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel_List_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel_List_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_List1

    ui_List1 = lv_obj_create(ui_Panel_List_Group);

    lv_obj_set_height(ui_List1, 50);
    lv_obj_set_width(ui_List1, lv_pct(102));

    lv_obj_set_x(ui_List1, 0);
    lv_obj_set_y(ui_List1, -1);

    lv_obj_set_align(ui_List1, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_List1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_List1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_List1, lv_color_hex(0x4B4F59), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_List1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_List1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_List1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_List1

    ui_Label_List1 = lv_label_create(ui_List1);

    lv_obj_set_width(ui_Label_List1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_List1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_List1, 19);
    lv_obj_set_y(ui_Label_List1, 0);

    lv_obj_set_align(ui_Label_List1, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Label_List1, "Quiet");

    lv_obj_set_style_text_color(ui_Label_List1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_List1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_List1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Switch1

    ui_Switch1 = lv_switch_create(ui_List1);

    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);

    lv_obj_set_x(ui_Switch1, -30);
    lv_obj_set_y(ui_Switch1, 0);

    lv_obj_set_align(ui_Switch1, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_Switch1, lv_color_hex(0x5B606C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Switch1, lv_color_hex(0x186BD3), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Switch1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_color(ui_Switch1, lv_color_hex(0x32AFED), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui_Switch1, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_CHECKED);

    // ui_List4

    ui_List4 = lv_obj_create(ui_Panel_List_Group);

    lv_obj_set_height(ui_List4, 50);
    lv_obj_set_width(ui_List4, lv_pct(102));

    lv_obj_set_x(ui_List4, 0);
    lv_obj_set_y(ui_List4, 48);

    lv_obj_set_align(ui_List4, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_List4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_List4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_List4, lv_color_hex(0x4B4F59), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_List4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_List4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_List4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_List5

    ui_Label_List5 = lv_label_create(ui_List4);

    lv_obj_set_width(ui_Label_List5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_List5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_List5, 19);
    lv_obj_set_y(ui_Label_List5, 0);

    lv_obj_set_align(ui_Label_List5, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Label_List5, "Turbo");

    lv_obj_set_style_text_color(ui_Label_List5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_List5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_List5, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Switch2

    ui_Switch2 = lv_switch_create(ui_List4);

    lv_obj_set_width(ui_Switch2, 50);
    lv_obj_set_height(ui_Switch2, 25);

    lv_obj_set_x(ui_Switch2, -29);
    lv_obj_set_y(ui_Switch2, 0);

    lv_obj_set_align(ui_Switch2, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_bg_color(ui_Switch2, lv_color_hex(0x5B606C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Switch2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Switch2, lv_color_hex(0x186BD3), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Switch2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_color(ui_Switch2, lv_color_hex(0x32AFED), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui_Switch2, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_CHECKED);

    // ui_List2

    ui_List2 = lv_obj_create(ui_Panel_List_Group);

    lv_obj_set_height(ui_List2, 50);
    lv_obj_set_width(ui_List2, lv_pct(102));

    lv_obj_set_x(ui_List2, 0);
    lv_obj_set_y(ui_List2, 97);

    lv_obj_set_align(ui_List2, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_List2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_List2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_List2, lv_color_hex(0x4B4F59), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_List2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_List2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_List2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_List2

    ui_Label_List2 = lv_label_create(ui_List2);

    lv_obj_set_width(ui_Label_List2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_List2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_List2, 19);
    lv_obj_set_y(ui_Label_List2, 0);

    lv_obj_set_align(ui_Label_List2, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Label_List2, "Fan swing");

    lv_obj_set_style_text_color(ui_Label_List2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_List2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_List2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Dropdown1

    ui_Dropdown1 = lv_dropdown_create(ui_List2);
    lv_dropdown_set_options(ui_Dropdown1, "Off\nSlow\nFast");

    lv_obj_set_width(ui_Dropdown1, 101);
    lv_obj_set_height(ui_Dropdown1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Dropdown1, 82);
    lv_obj_set_y(ui_Dropdown1, 1);

    lv_obj_set_align(ui_Dropdown1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Dropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_pad_left(ui_Dropdown1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Dropdown1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Dropdown1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Dropdown1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_List3

    ui_List3 = lv_obj_create(ui_Panel_List_Group);

    lv_obj_set_height(ui_List3, 111);
    lv_obj_set_width(ui_List3, lv_pct(102));

    lv_obj_set_x(ui_List3, 0);
    lv_obj_set_y(ui_List3, 146);

    lv_obj_set_align(ui_List3, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_List3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_List3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_List3, lv_color_hex(0x4B4F59), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_List3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_List3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_List3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_List3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_List3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_List3

    ui_Label_List3 = lv_label_create(ui_List3);

    lv_obj_set_width(ui_Label_List3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_List3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_List3, 19);
    lv_obj_set_y(ui_Label_List3, 0);

    lv_obj_set_align(ui_Label_List3, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Label_List3, "Zone");

    lv_obj_set_style_text_color(ui_Label_List3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_List3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_List3, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Checkbox1

    ui_Checkbox1 = lv_checkbox_create(ui_List3);
    lv_checkbox_set_text(ui_Checkbox1, "Bedroom");

    lv_obj_set_width(ui_Checkbox1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Checkbox1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Checkbox1, -45);
    lv_obj_set_y(ui_Checkbox1, -34);

    lv_obj_set_align(ui_Checkbox1, LV_ALIGN_RIGHT_MID);

    lv_obj_add_flag(ui_Checkbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_color(ui_Checkbox1, lv_color_hex(0xA8B0BB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Checkbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Checkbox1, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Checkbox1, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Checkbox2

    ui_Checkbox2 = lv_checkbox_create(ui_List3);
    lv_checkbox_set_text(ui_Checkbox2, "Kitchen");

    lv_obj_set_width(ui_Checkbox2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Checkbox2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Checkbox2, -56);
    lv_obj_set_y(ui_Checkbox2, 0);

    lv_obj_set_align(ui_Checkbox2, LV_ALIGN_RIGHT_MID);

    lv_obj_add_flag(ui_Checkbox2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_color(ui_Checkbox2, lv_color_hex(0xA8B0BB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Checkbox2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Checkbox2, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Checkbox2, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Checkbox3

    ui_Checkbox3 = lv_checkbox_create(ui_List3);
    lv_checkbox_set_text(ui_Checkbox3, "Livingroom");

    lv_obj_set_width(ui_Checkbox3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Checkbox3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Checkbox3, -33);
    lv_obj_set_y(ui_Checkbox3, 33);

    lv_obj_set_align(ui_Checkbox3, LV_ALIGN_RIGHT_MID);

    lv_obj_add_state(ui_Checkbox3, LV_STATE_CHECKED);

    lv_obj_add_flag(ui_Checkbox3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_color(ui_Checkbox3, lv_color_hex(0xA8B0BB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Checkbox3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Checkbox3, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Checkbox3, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Group_Roller

    ui_Group_Roller = lv_obj_create(ui_Panel_List_Group);

    lv_obj_set_width(ui_Group_Roller, 242);
    lv_obj_set_height(ui_Group_Roller, 143);

    lv_obj_set_x(ui_Group_Roller, 0);
    lv_obj_set_y(ui_Group_Roller, 260);

    lv_obj_set_align(ui_Group_Roller, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Group_Roller, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Group_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Group_Roller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Group_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Group_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Group_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Group_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Group_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Group_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_List4

    ui_Label_List4 = lv_label_create(ui_Group_Roller);

    lv_obj_set_width(ui_Label_List4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_List4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_List4, 0);
    lv_obj_set_y(ui_Label_List4, 12);

    lv_obj_set_align(ui_Label_List4, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_Label_List4, "Mode selection");

    lv_obj_set_style_text_color(ui_Label_List4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_List4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_List4, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Roller1

    ui_Roller1 = lv_roller_create(ui_Group_Roller);
    lv_roller_set_options(ui_Roller1, "Cool\nHeat\nFan\nAuto", LV_ROLLER_MODE_INFINITE);

    lv_obj_set_width(ui_Roller1, 129);
    lv_obj_set_height(ui_Roller1, 87);

    lv_obj_set_x(ui_Roller1, 0);
    lv_obj_set_y(ui_Roller1, 14);

    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);

    lv_obj_set_style_text_color(ui_Roller1, lv_color_hex(0x949494), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Roller1, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller1, lv_color_hex(0x626363), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Roller1, lv_color_hex(0x3D424B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Roller1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Roller1, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Roller1, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller1, lv_color_hex(0x038CEB), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Roller1, lv_color_hex(0x5A6269), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Roller1, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Roller1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_Panel_Menu1

    ui_Panel_Menu1 = lv_obj_create(ui_Settings);

    lv_obj_set_width(ui_Panel_Menu1, 61);
    lv_obj_set_height(ui_Panel_Menu1, 41);

    lv_obj_set_x(ui_Panel_Menu1, 15);
    lv_obj_set_y(ui_Panel_Menu1, -5);

    lv_obj_clear_flag(ui_Panel_Menu1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Panel_Menu1, ui_event_Panel_Menu1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_Panel_Menu1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel_Menu1, lv_color_hex(0x35B5F0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Menu1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel_Menu1, lv_color_hex(0x1767D2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel_Menu1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel_Menu1, lv_color_hex(0x5A606B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel_Menu1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_Menu1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Panel_Menu1, lv_color_hex(0x12B0FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_opa(ui_Panel_Menu1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_width(ui_Panel_Menu1, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_outline_pad(ui_Panel_Menu1, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Panel_Menu1, lv_color_hex(0x12B0FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Panel_Menu1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Panel_Menu1, 80, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Panel_Menu1, 4, LV_PART_MAIN | LV_STATE_PRESSED);

    // ui_ALbel_Back

    ui_ALbel_Back = lv_label_create(ui_Panel_Menu1);

    lv_obj_set_width(ui_ALbel_Back, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ALbel_Back, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ALbel_Back, 0);
    lv_obj_set_y(ui_ALbel_Back, 2);

    lv_obj_set_align(ui_ALbel_Back, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_ALbel_Back, "BACK");

    lv_obj_set_style_text_color(ui_ALbel_Back, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ALbel_Back, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ALbel_Back, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Splash_screen_init();
    ui_HVAC_screen_init();
    ui_Settings_screen_init();
    lv_disp_load_scr(ui_Splash);
}

