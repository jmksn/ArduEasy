//
// Created by jhonatan on 22/03/2020.
//

#ifndef ARDUEASY_LIST_H
#define ARDUEASY_LIST_H

template<class T>
struct Node {
    T *data;
    Node *prev, *next;
};

template<class T>
class List {
private:
    Node<T> *head;
    Node<T> *last;
    Node<T> *curr;
    unsigned int size;
public:
    List();

    ~List();

    void add(T *d);

    bool remove(T *d);

    void pop();

    template<class F>
    void forEach(F f);

    void clear(bool delete_data = false);

    unsigned int getSize();

    T *first();

    bool hasNext();

    T *next();

    T* getCurr();

};

#include "List.tpp"

#endif //ARDUEASY_LIST_H
