//
// Created by Журавлев  Роман on 20.09.2018.
//

#include "Shape.h"

Shape::Shape(){
    this->point.x = 0.0;
    this->point.y = 0.0;
}
Shape::Shape(float x, float y, float angle){
    this->point.x = x;
    this->point.y = y;
    this->angle = angle;
}

Shape::Shape(Point point, float angle) {
    this->point = point;
    this->angle = angle;
}

void Shape::setX(float x){
    this->point.x = x;
}
void Shape::setY(float y){
    this->point.y = y;
}
float Shape::getX(){
    return this->point.x;
}
float Shape::getY(){
    return this->point.y;
}

void Shape::move(float x, float y){
    this->point.x = x;
    this->point.y = y;

}
void Shape::move(Point point){
    this->point = point;

    cout<< this->getClassName() << ": "<< typeid(this).name()<< " moved to {" << point.x << "," << point.y << "}";
}

Point Shape::getPoint(){
    return this->point;
}

void Shape::rotate(float angle) {
    this->angle += angle;
}