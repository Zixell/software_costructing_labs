//
// Created by Журавлев  Роман on 20.09.2018.
//

#include "Text.h"

Text:: Text():Shape(){
    this->text = "";
};
Text::Text(string text, float x, float y, float angle):Shape(x, y, angle) {
    this->text = text;
}

Text::Text(string text, Point point, float angle) : Shape(point, angle){
    this->text = text;
}

void Text::setText(string text) {
    this->text = text;
}
string Text::getText() {
    return this->text;
}

void Text::getShapeInfo(ostream& os){
    os << typeid(this).name() << ": text located at (x: "<< this->getX() << ", y: "<< this->getY() << ") Text: " << this->getText()<<endl;
}

string Text::getClassName() {
    return std::string("Text");
}

void Text::resize(float times) {
    this->fontSize = round(this->fontSize * times);

}

void Text::serealize(ofstream& f) {
    f << this->getClassName()<<" "<<this->getX()<<" "<<this->getY()<<" "<<this->angle<<" "<<this->getText()<<endl;
}


