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
        head = nullptr;
        tail = nullptr;
    }

    bool is_empty(){
        return (head == nullptr);
    }

    void push_back(T val){

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

    void push_front(T val)
    {
        node<T>* newNode = new node<T>;
        newNode->value = val;
        newNode->next = head;
        head = newNode;
    }

    void pop_front(){
        node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back(){

        if(!(head->next == nullptr)){
            node<T> *temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }

        delete head;
        head = nullptr;
    } 

    void del(){

    }

    void update(){

    }

    void display(){
        node<T> *curr = head;
        // cout << "list: " << " ";
        while(curr != nullptr)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
    }

    // void clear(){
    //     while(head!= nullptr){
    //         Nodo<T>* temp = head;
    //         head = head->next;
    //         delete temp;
    //     }
    // }
};



int main(){

    // ex1();
    // ex2();
    // ex3();
   
    return 0;
}

void ex1(){

    SLL<string> l1;

    // cout << boolalpha << l1.is_empty() << endl;;

    // l1.push_back("The Beatles");
    // l1.push_back("-");
    // l1.push_back(" Across The Universe");
    // cout <<
    // cout << boolalpha << l1.is_empty() << endl;

    // l1.display();
}

void ex2(){

    SLL <int> l2;

    cout << boolalpha << l2.is_empty() << endl;

    l2.push_back(5);
    // l2.push_back(3);
    // l2.push_back(8);
    // l2.push_back(1);

    // l2.push_front(88);
    // l2.push_front(77);

    // l2.push_back(14);
    // l2.push_back(51);

    // l2.push_front(99);
    // l2.push_front(90);

    // l2.pop_front();
    // l2.pop_front();
    // l2.pop_front();
    // l2.pop_front();

    l2.display();

    l2.pop_back();

    l2.display();
}

