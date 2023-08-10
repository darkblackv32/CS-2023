#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <iostream>

#include "list.h"

template <typename T>
class CircularList : public List<T> 
{
private:
    Node<T>* head;
    int nodes;
public:
    CircularList(){}
    ~CircularList(){ this->clear(); }
    std::string name() { return "CircularList"; }
    T front(){}
    T back(){}
    void push_front(T data){}
    void push_back(T data){}
    T pop_front(){}
    T pop_back(){}
    void insert(T data, int pos){}
    T& operator[](int index){}
    bool is_empty() {}
    int size() {}
    void clear(){}
    void display(){}
    void sort(){}
    bool is_sorted(){}
    void reverse(){}
    void remove(int pos){}
};

#endif
