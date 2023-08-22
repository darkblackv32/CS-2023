#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void ex1(), ex2(), ex3();

template<typename T>

struct node{
    T value;
    node<T> *next;
};


template<typename T>
class SLL{
private:
    node<T> *head;
    node<T> *tail;
public:

    SLL(){
        tail = nullptr;
        head = nullptr;
    }

    bool is_empty(){
        return (head == nullptr);
    }

    void pb(T val){

        node<T>* newNode = new node<T>;
        newNode->value = val; 
        newNode->next = nullptr; //! cos it's the last element

        if(!is_empty()){ // not empty
            node<T> *curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = newNode;
        }
        else head = newNode;
    }

    void pf(T val)
    {
        node<T>* newNode = new node<T>;
        newNode->value = val;
        newNode->next = head;
        head = newNode;
    }


    void del(){

    }

    void update(){

    }

    void print(){
        node<T> *curr = head;
        while(curr != nullptr)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
    }

};


int main(){

    // ex1();
    ex2();
    // ex3();
   
    return 0;
}

void ex1(){

    SLL<string> l1;

    // cout << boolalpha << l1.is_empty() << endl;;

    // l1.pb("The Beatles");
    // l1.pb("-");
    // l1.pb(" Across The Universe");
    // cout <<
    // cout << boolalpha << l1.is_empty() << endl;

    // l1.print();
}

void ex2(){

    SLL <int> l2;

    cout << boolalpha << l2.is_empty() << endl;

    l2.pb(5);
    l2.pb(3);
    l2.pb(8);
    l2.pb(1);

    l2.pf(88);
    l2.pf(77);

    l2.pb(14);
    l2.pb(51);

    l2.pf(99);
    l2.pf(90);

    l2.print();
}