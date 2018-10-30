//
// Created by Журавлев  Роман on 20.09.2018.
//

#include "RegularPolygon.h"


RegularPolygon::RegularPolygon(){
    this->dimensions = 0;
}
RegularPolygon::RegularPolygon(int dim, float rad, float x, float y):Circle(rad,x,y){
    this->dimensions = dim;
}
RegularPolygon::RegularPolygon(int dim, float rad, Point point):Circle(rad, point){

    this->dimensions = dim;
}

void RegularPolygon::getShapeInfo(ostream& os){
    os<< "Regular polygon "<< typeid(this).name() <<  " at (x: " << this->getX() << ", y: " << this->getY() << ") " << endl;
}

string RegularPolygon::getClassName() {
    return std::string("RegularPolygon");
}


