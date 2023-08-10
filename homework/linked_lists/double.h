#ifndef DOUBLY_H
#define DOUBLY_H

#include "node.h"

// TODO: Implement all methods
template <typename T>
class DoublyList : public List<T> 
{
private:
    Node<T>* head;
    int nodes;
public:
    DoublyList(){}
    ~DoublyList(){ this->clear(); }
    std::string name() { return "DoublyList"; }
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
    void clear(){this->head->killSelf(); }
    void display(){}
    void sort(){}
    bool is_sorted(){}
    void reverse(){}
    void remove(int pos){}
};

#endif