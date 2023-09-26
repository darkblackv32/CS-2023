#include "sll.h"

void test1(){
    Node* head = nullptr;
    push_front(head, 5);
    push_front(head, 10);
    push_front(head, 4);
    push_front(head, 8);
    push_front(head, 2);
    display(head);//2->8->4->10->5->
    reverse(head);
    cout << endl; 
    display(head);//5->10->4->8->2->
}


void test2()
{
    Node* head1 = nullptr;    
    push_front(head1, 10);
    push_front(head1, 8);
    push_front(head1, 4);
    push_front(head1, 2);
    Node* head2 = nullptr;    
    push_front(head2, 9);
    push_front(head2, 8);
    push_front(head2, 7);
    push_front(head2, 5);
    push_front(head2, 2);
    Node* head3 = intersect(head1, head2);//O(n)
    display(head3);//2->8->
}


int main(){
    //1- Invertir lista
    // test1();
    //2- 
    test2();
}

