//
// Created by Журавлев  Роман on 20.09.2018.
//

#ifndef CONSSW_TEXTINSHAPE_H
#define CONSSW_TEXTINSHAPE_H

#include "Text.h"
#include "Circle.h"

class TextInShape : public Text, Circle{
private:
    Shape *shape;


public:
    TextInShape();
    TextInShape(string text, Shape * shape);

    void getShapeInfo(ostream& os);
    string getClassName();

};


#endif //CONSSW_TEXTINSHAPE_H
