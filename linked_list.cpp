#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


// template<typename T>

struct node{
    int value;
    node *nextId;
};



// template<typename T>
class SLL{
private:
    node *head;
    node *tail;
public:
    SLL(){
        tail = nullptr;
        head = nullptr;
    }

    bool is_empty(){
        return (head == nullptr);
    }

    void pb(int val){

        node* newNode = new node;
        newNode->value = val; 
        newNode->nextId = nullptr; //! cos it's the last element

        if(!is_empty()){
            node *curr = head;
            while(curr->nextId != nullptr){
                curr = curr->nextId;
            }
            curr->nextId = newNode;
        }


        else head = newNode;


    }

    void print(){
        node *curr = head;
        while(curr != nullptr)
        {
            cout << curr->value;
            curr = curr->nextId;
        }
    }

};

int main(){

    SLL l1;

    cout << boolalpha << l1.is_empty();

    l1.pb(8);
    l1.pb(10);

    cout << boolalpha << l1.is_empty()<<endl;

    l1.print();
    






    return 0;
}

