#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


template<typename T>

struct node{
    T value;
    node<T> *nextId;
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
        newNode->nextId = nullptr; //! cos it's the last element

        if(!is_empty()){ // not empty
            node<T> *curr = head;
            while(curr->nextId != nullptr){
                curr = curr->nextId;
            }
            curr->nextId = newNode;
        }


        else head = newNode;

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
            curr = curr->nextId;
        }
    }

};

int main(){

    SLL<string> l1;

    cout << boolalpha << l1.is_empty();

    l1.pb("The Beatles");
    l1.pb("-");
    l1.pb(" Across The Universe");

    cout << boolalpha << l1.is_empty()<<endl;

    l1.print();
    


    return 0;
}

