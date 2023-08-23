#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void push_front(Node* &head, int data)
{
    Node* n_node = new Node;
    n_node->data = data;
    n_node->next = head;
    head = n_node;
}

void display(Node* head)
{
    Node* crr = head;

    while(crr != nullptr){
        cout << crr->data << " ";
        crr = crr->next;
    }
}

void reverse(Node* &head)
{       
    // 8 - 9 - 7 
    Node* curr = head; // curr = 8
    Node* prev = nullptr;   
    Node* next = nullptr;

    while (curr != nullptr){ // T, T
        next = curr->next; // next = 9. 
        curr->next = prev; // curr.next = nullptr
        prev = curr; // prev = 8
        curr = next; // 9
    }
    head = prev;
}

Node* intersect(Node* head1, Node* head2){
    Node temp;
    Node* prev = &temp;
    temp.next = nullptr;

     while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data == head2->data)
        {
            push_front((prev->next), head1->data);
            prev = prev->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
            head1 = head1->next;
        else
            head2 = head2->next;
    }
    return (temp.next);
}

// Node* union(Node* head1, Node* head2){
//     Node temp;
//     Node* prev = &temp;
//     temp.next = nullptr; 
// }
