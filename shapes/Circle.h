//
// Created by Журавлев  Роман on 20.09.2018.
//
#include "Shape.h"

#ifndef CONSSW_CIRCLE_H
#define CONSSW_CIRCLE_H


class Circle: public Shape {
protected:
     float radius;

public:
    Circle();
    Circle(float radius, float x = 0.0, float y = 0.0, float angle = 0.0);
    Circle(float radius, Point point = {0.0, 0.0}, float angle = 0.0);

   float getRadius();
   void resize(float times);

    void serealize(ofstream& f){}

    void getShapeInfo(ostream& os){
        os << this->getClassName() << this->radius << " at ("<<this->getX()<<", "<<this->getY()<<")"<<endl;
    }

    string getClassName(){
        return "Circle";
    }
};


#endif //CONSSW_CIRCLE_H
