#pragma once
#include <Arduino.h>

namespace Pins {
    #ifdef BLUEPILL_ENV
    // MOTOR DRIVERS
    constexpr int DRIVER_0_A = PB12;
    constexpr int DRIVER_0_B = PB13;
    constexpr int DRIVER_0_PWM = PB1;

    constexpr int DRIVER_1_A = PB14;
    constexpr int DRIVER_1_B = PB15;
    constexpr int DRIVER_1_PWM = PB0;

    constexpr int DRIVER_2_A = PA11;
    constexpr int DRIVER_2_B = PA12;
    constexpr int DRIVER_2_PWM = PB9;

    constexpr int DRIVER_3_A = PA15;
    constexpr int DRIVER_3_B = PB3;
    constexpr int DRIVER_3_PWM = PB8;

    // LINE SENSORS
    constexpr int LINE_N_INSIDE = PA5;
    constexpr int LINE_N_OUTSIDE = PA4;

    constexpr int LINE_E_INSIDE = PA3;
    constexpr int LINE_E_OUTSIDE = PA2;

    constexpr int LINE_S_INSIDE = PA1;
    constexpr int LINE_S_OUTSIDE = PA0;

    constexpr int LINE_W_INSIDE = PA7;
    constexpr int LINE_W_OUTSIDE = PA6;

    // SERIALS
    constexpr int ESP32_TX = PB10;
    constexpr int ESP32_RX = PB11;

    constexpr int CAMERA_TX = PA9;
    constexpr int CAMERA_RX = PA10;

    // SWITCHES
    constexpr int SWITCH_1 = PC14;
    constexpr int SWITCH_2 = PC13;
    constexpr int SWITCH_3 = PC15;

    // ADVANCED FEATURES
    constexpr int BALL_PRESENCE = PB4;
    constexpr int KICKER = PA8;
    constexpr int ROLLER = PB5;
    #endif

    #ifdef TEENSY41_ENV
    // MOTOR DRIVERS
    constexpr int DRIVER_0_A = 9;
    constexpr int DRIVER_0_B = 10;
    constexpr int DRIVER_0_PWM = 4;

    constexpr int DRIVER_1_A = 11;
    constexpr int DRIVER_1_B = 12;
    constexpr int DRIVER_1_PWM = 5;

    constexpr int DRIVER_2_A = 29;
    constexpr int DRIVER_2_B = 30;
    constexpr int DRIVER_2_PWM = 2;

    constexpr int DRIVER_3_A = 31;
    constexpr int DRIVER_3_B = 32;
    constexpr int DRIVER_3_PWM = 3;

    // LINE SENSORS
    constexpr int LINE_N_INSIDE = A7;
    constexpr int LINE_N_OUTSIDE = A6;

    constexpr int LINE_E_INSIDE = A3;
    constexpr int LINE_E_OUTSIDE = A2;

    constexpr int LINE_S_INSIDE = A1;
    constexpr int LINE_S_OUTSIDE = A0;

    constexpr int LINE_W_INSIDE = A9;
    constexpr int LINE_W_OUTSIDE = A8;

    // SERIALS
    #define BALL_SERIAL Serial2
    #define CAMERA_SERIAL Serial6

    // SWITCHES -- TO CHECK
    constexpr int SWITCH_1 = A17;
    constexpr int SWITCH_2 = A16;
    constexpr int SWITCH_3 = A15;

    // ADVANCED FEATURES
    constexpr int BALL_PRESENCE = A13;
    constexpr int KICKER = 33;
    constexpr int ROLLER = 28;
    #endif

    #ifdef TEENSY35_ENV
    // MOTOR DRIVERS
    constexpr int DRIVER_0_A = 29;
    constexpr int DRIVER_0_B = 28;
    constexpr int DRIVER_0_PWM = 3;

    constexpr int DRIVER_1_A = 12;
    constexpr int DRIVER_1_B = 11;
    constexpr int DRIVER_1_PWM = 4;

    constexpr int DRIVER_2_A = 25;
    constexpr int DRIVER_2_B = 24;
    constexpr int DRIVER_2_PWM = 5;

    constexpr int DRIVER_3_A = 27;
    constexpr int DRIVER_3_B = 26;
    constexpr int DRIVER_3_PWM = 2;

    // LINE SENSORS
    constexpr int LINE_N_INSIDE = 20;
    constexpr int LINE_N_OUTSIDE = 21;

    constexpr int LINE_E_INSIDE = 17;
    constexpr int LINE_E_OUTSIDE = 16;

    constexpr int LINE_S_INSIDE = 15;
    constexpr int LINE_S_OUTSIDE = 14;

    constexpr int LINE_W_INSIDE = 23;
    constexpr int LINE_W_OUTSIDE = 22;

    // SERIALS
    #define BALL_SERIAL Serial2
    #define CAMERA_SERIAL Serial3

    // SWITCHES -- TO CHECK
    constexpr int SWITCH_1 = 39;
    constexpr int SWITCH_2 = 38;
    constexpr int SWITCH_3 = 33;

    // ADVANCED FEATURES
    constexpr int BALL_PRESENCE = A13;
    constexpr int KICKER = 34;
    //TODO: CHECK ROLLER PIN
    constexpr int ROLLER = 255;
    #endif
}