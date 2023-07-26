#include <bits/stdc++.h>
using namespace std;


template<typename T>

struct Node{
    T value;
    Node *next;
};



template<typename T>
class List{
private:
    Node *head, *tail;
public:
    list(){
        *tail = nullptr;
        *head = nullptr;
    }

};

