#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){}
    Node(T value){}

    void killSelf()
    {
        // recursion | elimina a todos los elementos a los que esta conectado y a si mismo
    }
};

#endif