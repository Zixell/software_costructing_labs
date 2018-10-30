//
// Created by Журавлев  Роман on 20.09.2018.
//

#ifndef CONSSW_REGULARPOLYGON_H
#define CONSSW_REGULARPOLYGON_H

#include "Circle.h"

class RegularPolygon : public Circle{

private:
    int dimensions;

public:
    RegularPolygon();
    RegularPolygon(int dim, float rad, float x = 0.0, float y = 0.0);
    RegularPolygon(int dim, float rad, Point point = {x: 0.0, y: 0.0});



    void getShapeInfo(ostream& os);
    string getClassName();

    void serealize(ofstream& f){}
};


#endif //CONSSW_REGULARPOLYGON_H
