// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Thermostat

#include "ui.h"

void Popup_Animation(lv_obj_t * TargetObject, int delay);

static void popup_anim_timer(lv_timer_t * t)
{
    Popup_Animation(ui_Popup, 0);
}

void toast_anim_start(lv_event_t * e)
{
    lv_timer_create(popup_anim_timer, 20000, NULL);
	// Your code here
}

void fan_speed_value(lv_event_t * e)
{
	// Your code here
}
