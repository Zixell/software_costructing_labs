//
// Created by Журавлев  Роман on 20.09.2018.
//

#ifndef CONSSW_SHADOWEDREGULARPOLYGON_H
#define CONSSW_SHADOWEDREGULARPOLYGON_H

#include "RegularPolygon.h"

struct RGB{
    float R;
    float G;
    float B;
};

class ShadowedRegularPolygon : public RegularPolygon{
private:
    int shadowBorder;
    RGB shadowColor;

public:
    ShadowedRegularPolygon();
    ShadowedRegularPolygon(int shadowBorder, int dim, float rad, RGB shadowColor = {0.0, 0.0, 0.0}, float x = 0.0, float y = 0.0);
    ShadowedRegularPolygon(int shadowBorder, int dim, float rad, RGB shadowColor = {0.0, 0.0, 0.0}, Point point = {0.0, 0.0});

    void getShapeInfo(ostream& os);
    string getClassName();

    void serealize(ofstream& f){}
};


#endif //CONSSW_SHADOWEDREGULARPOLYGON_H
