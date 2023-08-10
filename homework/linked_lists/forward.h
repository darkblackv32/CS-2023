#ifndef FORWARD_H
#define FORWARD_H


#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> 
{
private:
    Node<T>* head;
    int nodes;
public:
    ForwardList(){}
    ~ForwardList(){ this->clear(); }
    std::string name() { return "ForwardList"; }
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