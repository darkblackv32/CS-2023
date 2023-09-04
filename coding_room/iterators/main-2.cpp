#include <iostream>
#include "circular_array.h"


using namespace std;

int main()
{
    CircularArray<int> arr(5); 
    CircularArray<int>::iterator ptr;

    arr.push_front(10);
    arr.push_front(12);
    arr.push_back(2);
    arr.push_back(4);       

    // cout << "beg: " << *arr.begin() << endl;
    // cout << "end: " << *arr.end() << endl;


    // Displaying vector elements using begin() and end()
    for (ptr = arr.begin(); ptr != arr.end(); ++ptr)
        cout << *ptr << ",";
    cout<<endl;
    //12,10,2,4,

    // cout << "beg2: " << *arr.begin() << endl;
    // cout << "end2: " << *arr.end() << endl;

    arr.pop_back();arr.pop_back();arr.pop_back();
    arr.push_back(10);arr.push_back(8);arr.push_back(6);arr.push_back(4);     

    // cout << "beg3: " << *arr.begin() << endl;
    // cout << "end3: " << *arr.end() << endl;

    // Displaying vector elements using begin() and end()
    for (ptr = arr.begin(); ptr != arr.end(); ++ptr)
        cout << *ptr << ",";
    cout<<endl;        
    //12,10,8,6,4,

    ptr = arr.begin();
    ptr = ++ptr;    
    ptr = --ptr;
    cout<<*ptr<<endl;//12
            
    return 0; 
}