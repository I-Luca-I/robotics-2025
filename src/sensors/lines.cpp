#include <Arduino.h>
#include "sensors/lines.h"
#include "config.h"

Lines::Lines() {
    #ifdef ROCK
    thresholds[0] = 300; //130-950
    thresholds[1] = 300; //210-960
    
    thresholds[2] = 300; //140-920
    thresholds[3] = 300; //110-840
    
    thresholds[4] = 300; //120-950
    thresholds[5] = 300; //120-900
    
    thresholds[6] = 300; //200-960
    thresholds[7] = 300; //170-960
    
    #else
    thresholds[0] = 100; //20-170
    thresholds[1] = 150; //40-330

    thresholds[2] = 200; //50-420
    thresholds[3] = 400; //80-730
    
    thresholds[4] = 999999; //0-7 BROKEN
    thresholds[5] = 190; //180-210
    
    thresholds[6] = 350; //80-920
    thresholds[7] = 350; //70-700
    
    #endif
}

void Lines::read() {
    values[0] = analogRead(Pins::LINE_N_INSIDE);
    values[1] = analogRead(Pins::LINE_N_OUTSIDE);
    values[2] = analogRead(Pins::LINE_E_INSIDE);
    values[3] = analogRead(Pins::LINE_E_OUTSIDE);
    values[4] = analogRead(Pins::LINE_S_INSIDE);
    values[5] = analogRead(Pins::LINE_S_OUTSIDE);
    values[6] = analogRead(Pins::LINE_W_INSIDE);
    values[7] = analogRead(Pins::LINE_W_OUTSIDE);
    
    status = 0;
    if(values[0] > thresholds[0]) status |= 0b10000000;
    if(values[1] > thresholds[1]) status |= 0b01000000;
    if(values[2] > thresholds[2]) status |= 0b00100000;
    if(values[3] > thresholds[3]) status |= 0b00010000;
    if(values[4] > thresholds[4]) status |= 0b00001000;
    if(values[5] > thresholds[5]) status |= 0b00000100;
    if(values[6] > thresholds[6]) status |= 0b00000010;
    if(values[7] > thresholds[7]) status |= 0b00000001;
}
