//
// Created by Журавлев  Роман on 20.09.2018.
//

#include "ShadowedRegularPolygon.h"

ShadowedRegularPolygon::ShadowedRegularPolygon(){
    this->shadowBorder = 1;
}
ShadowedRegularPolygon::ShadowedRegularPolygon(int shadowBorder, int dim,float rad, RGB shadowColor, float x, float y):RegularPolygon(dim,rad, x,y){
    this->shadowBorder = shadowBorder;
    this->shadowColor = shadowColor;

}
ShadowedRegularPolygon::ShadowedRegularPolygon(int shadowBorder, int dim, float rad, RGB shadowColor, Point point):RegularPolygon(dim,rad, point){
    this->shadowBorder = shadowBorder;
    this->shadowColor = shadowColor;
}

void ShadowedRegularPolygon::getShapeInfo(ostream& os){
    os << "Shadowed regular polygon "<< typeid(this).name() <<  "at (x: " << this->getX() << ", y: " << this->getY() << "). Shadow: " <<this->shadowBorder << "px, color RGB = {" << this->shadowColor.R<<","<<this->shadowColor.G<<","<<this->shadowColor.B<<"}" << endl;
}

string ShadowedRegularPolygon::getClassName() {
    return std::string("ShadowedRegularPolygon");
}
