#include <iostream>
#include "circulararray.h"
#include "tester.h"

using namespace std;

void t1(), t2();

int main() {

    CircularArray<int>* array = new CircularArray<int>(1);
    // ASSERT(array->is_empty() == true, "The function is_empty is not working");

    int i = 20000;
    srand(time(NULL));
    while (i--)
    {
        int numero_random = rand() % 4;

        cout << numero_random << endl;
        // cout << array->to_string() << endl;

        switch (numero_random)
        {
        case 0:
            array->push_back(rand() % 50);
            break;
        case 1:
            array->push_front(rand() % 50);
            break;
        case 2:
            array->pop_back();
            break;
        case 3:
            array->pop_front();
            break;
        default:
            break;
        }
    }
    return 0;
}



void t1(){

    int a = 5;
    cout << a++ << endl;     // returns the value of a before the increment 5
    cout << a << endl;       // 6
    cout << ++a << endl;     // ++a returns the value after the increment 7

}

void t2(){

    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    cout << *ptr << endl; // 1 pointer points to the first element in the array
    cout << *ptr++ << endl; // *ptr=2 but it will print 1 (var++)
    cout << *++ptr << endl; // 3, next postition
    cout << ++*ptr << endl; // 4, next position
    cout << (*ptr)++ << endl; // *ptr=5 but it will print 4 (var++) 
    cout << *ptr << endl; // 5

}