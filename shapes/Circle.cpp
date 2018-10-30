//
// Created by Журавлев  Роман on 20.09.2018.
//

#include "Circle.h"

Circle::Circle(){
    radius = 0.0;
}

Circle::Circle(float radius, float x, float y, float angle):Shape(x,y, angle){
    this->radius = radius;
}


Circle::Circle(float radius, Point point, float angle):Shape(point, angle){
    this->radius = radius;
}

float Circle::getRadius() {
    return this->radius;
}

void Circle::resize(float times) {
    this->radius *= times;
}
