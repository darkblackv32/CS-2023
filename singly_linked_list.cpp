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
    node<T> *prev;
public:

    SLL(){
        head = nullptr;
        prev = nullptr;
    }

    ~SLL(){
        this->clear();
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

    void del(int pos){

    }

    void update(){

    }

    void display(){
        node<T> *curr = head;
        while(curr != nullptr)
        {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void clear(){
        while(head!= nullptr){
            node<T>* temp = new node<T>;
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    int size(){
        int it = 0;
        do{
            head = head->next;
            it++;
        }while(head->next != nullptr);
        return it;
    }

    T& operator [](int index){
        
        if(index == 0){
            return head->value;
        }

        for(int i = 0; i <= index; i++){
            head = head->next;
        }

        return head->value;
    }

    void reverse()
    {
        node<T>* temp = new node<T>;
        temp = head;

        while(head->next != nullptr)
        {
            temp->next;
            temp->next = head;
            head->next;
        }
        
    }

};



int main(){

    ex1();
    // ex2();
    // ex3();
   
    return 0;
}

void ex1(){

    SLL<string> l1;

    // cout << "is empty? " << boolalpha << l1.is_empty() << endl;

    l1.push_back("The Beatles");
    l1.push_back("-");
    l1.push_back("Across The Universe");
    l1.push_front("1.");
    // cout << "is empty? " << boolalpha << l1.is_empty() << endl;

    l1.display();

    cout << l1[0] << endl;

    cout << l1.size() << endl;

    l1.reverse();

    l1.display();

   
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

