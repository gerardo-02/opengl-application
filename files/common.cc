#include "common.h"

float propeller_angle = 1.0;
float tail_angle = 1.0;
float tail_size = 1.0;

void change_propeller_angle(float angle){
    propeller_angle += angle;
}

void change_tail_angle(float angle){
    tail_angle += angle;
}

void change_tail_size(float increment){
    tail_size += increment;
}

