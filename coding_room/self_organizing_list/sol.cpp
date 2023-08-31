#include <iostream>
#include "sol.h"


int main()
{
    Node* head = nullptr;
    for(int i=0;i<10;i++)
        push_front(head, (10-i)*2); 
    
    bool result = false;
    for(int i=0;i<5;i++){
        COUNT = 0;
        result = search_transpose(head, 16);     
        // display(head);   
        cout<<result<<" ("<<COUNT<<")"<<endl;
    }
    return 0;
}