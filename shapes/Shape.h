//
// Created by Журавлев  Роман on 20.09.2018.
//
#include "iostream"
#include "vector"
#include "fstream"
#include "string"

#include "../container/BinaryTree.h"

#ifndef CONSSW_SHAPE_H
#define CONSSW_SHAPE_H

using namespace std;

struct Point{
    float x, y;
};

class Shape {
protected:
    Point point;
    float angle;

public:
    Shape();
    Shape(float x, float y, float angle = 0.0);
    Shape(Point point, float angle = 0.0);
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();

    Point getPoint();

    void move(float x, float y);
    void move(Point point);

    void rotate(float angle);
    void resize(float times);

    friend std::ostream& operator<<(std::ostream &os, Shape &c) {
        c.getShapeInfo(os);
        //os  << typeid(c).name() << " (x: " << c.getX() << ", y: " << c.getY() << ")";
        return os;
    }



    virtual void getShapeInfo(ostream& os) = 0;
    virtual string getClassName() = 0;
    virtual void serealize(ofstream& f) = 0;


};




#endif //CONSSW_SHAPE_H
