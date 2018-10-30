//
// Created by Журавлев  Роман on 10.10.2018.
//

#ifndef CONSSW_BINARYTREEITERATOR_H
#define CONSSW_BINARYTREEITERATOR_H

template <typename T>
class BinaryTree;

template <typename T>
class BinaryTreeIterator {

    BinaryTree<T> *m_container;
    int m_pos;

public:
    BinaryTreeIterator(BinaryTree<T> *container = nullptr);

    BinaryTreeIterator<T> next();

    T &operator*();
    void setPos(int pos) { m_pos = pos; }

    bool operator==(const BinaryTreeIterator<T> &right);
    bool operator!=(const BinaryTreeIterator<T> &right);

};

template <typename T>
BinaryTreeIterator<T>::BinaryTreeIterator(BinaryTree<T> *container)
{
    m_container = container;
    m_pos = 0;
}

template<typename T>
BinaryTreeIterator<T> BinaryTreeIterator<T>::next()
{
    m_pos++;
    return *(this);
}

template<typename T>
T &BinaryTreeIterator<T>::operator*()
{
    return m_container->at(m_pos);
}

template<typename T>
bool BinaryTreeIterator<T>::operator==(const BinaryTreeIterator<T> &right)
{
    if(m_pos == right.m_pos) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool BinaryTreeIterator<T>::operator!=(const BinaryTreeIterator<T> &right)
{
    return !operator==(right);
}



#endif //CONSSW_BINARYTREEITERATOR_H
