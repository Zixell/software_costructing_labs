//
// Created by Журавлев  Роман on 10.10.2018.
//

#ifndef CONSSW_BINARYTREE_H
#define CONSSW_BINARYTREE_H

#include "BinaryTreeIterator.h"
#include "vector"
#include "../exceptions/OutOfRangeException.h"
#include "string"
#include "iostream"

using namespace std;

std::vector<std::string> split(const std::string& s);


template <typename T>
struct Node{
    T data;
    int weigth;
    Node<T>  *left, *right;
};

template <typename T>
class BinaryTreeIterator;

template <typename T>
class BinaryTree {
private:
    Node<T>* head;
    vector<Node<T>*> list;
public:
    BinaryTree(){
        this->head = NULL;
    }
    BinaryTree(Node<T>* head){
        this->head = head;
        cout << this->head->weigth << " - weight"<<endl;
    }

    int size() const { return list.size(); }

    typedef BinaryTreeIterator<T> iterator;
    T& at(int pos);

    void setHead(Node<T>* head){
        this->head = head;
        leftSearch(this->head);
    }

    Node<T>* getHead(){
        return head;
    }

    vector<Node<T>*> getList(){
        return list;
    }

    void push(Node<T>* root, T pushing, int weight){
        if(root == NULL) {
            root = new Node<T>();
            root->data = pushing;
            root->weigth = weight;
            root->left = root->right = NULL;
        }

        if (weight <= root->weigth) {
            if (root->left != NULL) push(root->left, pushing, weight);
            else {
                cout << "add element to left " << pushing->getClassName() << " w:" << weight << endl;
                root->left = new Node<T>;
                root->left->data = pushing;
                root->left->weigth = weight;
                root->left->left = root->left->right = NULL;
            }
        }

        if (weight > root->weigth) {
            if (root->right != NULL) push(root->right, pushing, weight);
            else {
                cout << "add element to right " << pushing->getClassName() << " w:" << weight << endl;
                root->right = new Node<T>;
                root->right->data = pushing;
                root->right->weigth = weight;
                root->right->left = root->right->right = NULL;
            }
        }

    }


    void leftSearch(Node<T> *node){

        if(node == NULL){
            return;
        }


        if(node->left != NULL){
            leftSearch(node->left);
        }

        if(node->right != NULL){
            leftSearch(node->right);
        }

        cout << node << endl;
        list.push_back(node);

    };



    BinaryTreeIterator<T> begin();
    BinaryTreeIterator<T> end();
};

template<typename T>
BinaryTreeIterator<T> BinaryTree<T>::begin()
{
    return BinaryTreeIterator<T>(this);
}

template <typename T>
T &BinaryTree<T>::at(int pos)
{
    if(pos >= list.size() || pos < 0)
        throw OutOfRangeException();

    return list.at(pos)->data;
}

template<typename T>
BinaryTreeIterator<T> BinaryTree<T>::end()
{
    BinaryTreeIterator<T> it = BinaryTreeIterator<T>(this);
    it.setPos(this->size());
    return it;
}


#endif //CONSSW_BINARYTREE_H
