#include <Arduino.h>
#include "sensors/sensors.h"
#include "control/control.h"
#include "behavior/bounds.h"
#include "behavior/behavior.h"
#include "behavior/keeper.h"

void keeper() {
    static unsigned long start_time;
    static byte game_state = RESET;

    switch (game_state) {
    case RESET:
        if (lines->status) {
            game_state = DEFEND;
            start_time = millis();
        } else {
            goto_goal();
        }
        break;

    case DEFEND:
        if (ball->seen and is_ball_close(ball->distance)) {
            game_state = PARRY;
            start_time = millis();
        } else if (millis() - start_time >= IDLE_TIME) {
            game_state = RESET;
        } else {
            if (lines->status) start_time = millis();
            defend();
        }
        break;

    case PARRY:
        if (
            !is_ball_close(ball->distance) or 
            millis() - start_time >= SAVE_TIME or 
            (ball->absolute_angle > 90 and ball->absolute_angle < 270) or 
            (millis() - start_time >= 100 and lines->status)
        ) {
            game_state = RESET;
        } else {
            save();
        }
        break;
    
    default:
        break;
    }
}

void goto_goal() {
    driver->orient = 0;
    driver->speed = SETUP_SPEED;

    if (!defence_goal->seen) driver->dir = 0;
    else if (defence_goal->angle > 90 and defence_goal->angle < 160) driver->dir = 55;
    else if (defence_goal->angle > 200 and defence_goal->angle < 270) driver->dir = 315;
    else driver->dir = 180;
}

void defend() {
    // driver->orient = (defence_goal->angle + 180) % 360;
    // driver->orient = (ball->seen) ? ball->absolute_angle : 0;
    driver->orient = 0;
    driver->absolute = true;
    driver->speed = 0;

    // if (!ball->seen or (ball->absolute_angle > 10 and ball->absolute_angle < 350)) stay_on_line(lines->status);
    stay_on_line(lines->status);

    if (ball->absolute_angle < 90) driver->dy = map(ball->absolute_angle, 0, 90, GAME_SPEED/2, GAME_SPEED*4);
    if (ball->absolute_angle > 270) driver->dy = -map(ball->absolute_angle, 270, 360, GAME_SPEED*4, GAME_SPEED/2);
    if (!ball->seen) driver->dy = 0;
    
    if ((defence_goal->angle > 220 or is_goal_visible(defence_goal->angle)) and driver->dy > 0) driver->dy = 0;
    if ((defence_goal->angle < 140 or is_goal_visible(defence_goal->angle)) and driver->dy < 0) driver->dy = 0;
}

void save() {
    driver->speed = GAME_SPEED;
    driver->orient = 0;

    if      (ball->absolute_angle < 90)  driver->dir = ball->absolute_angle * 1.75;
    else if (ball->absolute_angle > 270) driver->dir = (360 - ((360 - ball->relative_angle) * 1.75));
    else driver->speed = 0;
}
