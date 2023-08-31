#include <iostream>
using namespace std;

int COUNT = 0;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void push_front(Node *&head, int value) {
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = head;
    new_node->prev = nullptr;
    if (head != nullptr)
        head->prev = new_node;
    head = new_node;
}

bool search_transpose(Node *&head, int value) {
    Node *faster = head;
    Node *slower = head;
    int temp = 0;
    
    while (faster->data != value) {
        if (faster->next == nullptr)
            return false;
        faster = faster->next;
        COUNT++;
        temp++;
        if (temp % 2  == 0) {
            slower = slower->next;
            temp = 0;
        }
    }
    
    if (faster == head)
        return true;
    
    faster->prev->next = faster->next;
    if (faster->next != nullptr)
        faster->next->prev = faster->prev;
    
    faster->next = slower;
    faster->prev = slower->prev;
    slower->prev = faster;
    
    if (faster->prev != nullptr)
        faster->prev->next = faster;
    else
        head = faster;

    return true;
}