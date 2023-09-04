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

    // Displaying vector elements using begin() and end()
    for (ptr = arr.begin(); ptr != arr.end(); ++ptr)
        cout << *ptr << "\n";
    //12,10,2,4,

    arr.push_back(6);       
    // Displaying vector elements using begin() and end()
    for (ptr = arr.begin(); ptr != arr.end(); ++ptr)
        cout << *ptr << "\n";
    //12,10,2,4,6,
            
    return 0; 
}