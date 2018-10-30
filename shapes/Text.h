//
// Created by Журавлев  Роман on 20.09.2018.
//

#ifndef CONSSW_TEXT_H
#define CONSSW_TEXT_H


#include "Shape.h"
#include "string"
#include "math.h"

class Text : public Shape{
private:
    string text;
    int fontSize;
public:
    Text();
    Text(string text, float x = 0.0, float y = 0.0, float angle = 0.0);
    Text(string text, Point point = {x:0.0, y:0.0}, float angle = 0.0);
    void setText(string text);
    string getText();

    void resize(float times);
    void serealize(ofstream& f);
    void getShapeInfo(ostream& os);
    string getClassName();
};


#endif //CONSSW_TEXT_H
