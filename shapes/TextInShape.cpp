//
// Created by Журавлев  Роман on 20.09.2018.
//

#include "TextInShape.h"

TextInShape::TextInShape() {
    this->shape = NULL;
}


TextInShape::TextInShape(string text, Shape *shape):Text(text, shape->getX(), shape->getY()) {
    this->shape = shape;
}

void TextInShape::getShapeInfo(ostream& os){
    os<< "Text: "<< this->getText() << " on (x: " << this->Circle::getX() << ", y: " << this->Circle::getY() << ") placed in object: " << this->shape->getClassName();
}

string TextInShape::getClassName(){
    return std::string("TextInShape");
}
