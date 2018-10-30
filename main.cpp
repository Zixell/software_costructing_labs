#include <iostream>
#include "shapes/Shape.h"
#include "shapes/Text.h"
#include "shapes/TextInShape.h"
#include "shapes/RegularPolygon.h"
#include "shapes/ShadowedRegularPolygon.h"
#include "container/BinaryTree.h"
#include "container/BinaryTreeIterator.h"
#include "math.h"
#include "shapes/Circle.h"
#include "fstream"

bool space(char c){
    return std::isspace(c);
}

bool notspace(char c){
    return !std::isspace(c);
}

//break a sentence into words
std::vector<std::string> split(const std::string& s){
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter i = s.begin();
    while(i!=s.end()){
        i = std::find_if(i, s.end(), notspace); // find the beginning of a word
        iter j= std::find_if(i, s.end(), space); // find the end of the same word
        if(i!=s.end()){
            ret.push_back(std::string(i, j)); //insert the word into vector
            i = j; // repeat 1,2,3 on the rest of the line.
        }
    }
    return ret;
}

Shape* deserealize(ifstream& f){
        string temp;

        while(getline(f,temp)){
            vector<string> tmp = split(temp);

            string className = tmp.front();

            if(className == "Text"){
                Text* newObj = new Text(tmp.at(4), std::stof(tmp.at(1)), std::stof(tmp.at(2)), std::stof(tmp.at(3)));
                return newObj;
            }

        }
}

int main() {

    std::ofstream f;
    std::ifstream i;

    f.open("../objects.txt", std::ios::app);
    i.open("../objects.txt");

    Text *s = new Text("Hello,World!", 2.0, 3.1);

    s->serealize(f);

    Shape *con =  deserealize(i);

    cout << *con << " - deserealizeted" << endl;

    f.close();
    i.close();

    RegularPolygon *rp = new RegularPolygon(4, 3, {3.1, 2.6});

    ShadowedRegularPolygon * srp = new ShadowedRegularPolygon(2, 5, 4, {0.7, 0.3, 0.4}, {0.3, 1.5});

    TextInShape *textInShape = new TextInShape("Hello again!", rp);

    Circle *cr = new Circle(5, 3, 5, 5.6);


//
//    cout<< "No iterator: " << *s << endl;
//    cout<< "No iterator: " << *rp << endl;
//    cout<< "No iterator: " << *srp << endl;
//    cout<< "No iterator: " <<*textInShape << endl;

    //rp->move({7.1, 5.2});

    //cout << endl << endl << *rp << endl;


    Node<Shape*> nd;
    nd.data = s;
    nd.weigth = 10;
    nd.left = nd.right = NULL;


    cout << "Start searching... " << endl;



    BinaryTree<Shape*> *bt = new BinaryTree<Shape*>(&nd);
    bt->push(bt->getHead(), rp, 7);
    bt->push(bt->getHead(), srp, 8);
    //bt->push(bt->getHead(), textInShape, 10);
    bt->push(bt->getHead(), cr, 5);

    bt->leftSearch(bt->getHead());

    cout << "Searching finished successfully." << endl;




    vector<Node<Shape*>*> lst = bt->getList();

    cout << bt->getList().size() << " - size" << endl;

    for(int i = 0; i < lst.size(); i++){
        cout << lst.at(i)->data->getClassName() << ": "<<lst.at(i)->weigth<<"   ";
    }
    cout << endl;
    for(BinaryTreeIterator<Shape*> it = bt->begin(); it != bt->end(); it.next()){
        cout << **it << endl;
    }


    return 0;
}