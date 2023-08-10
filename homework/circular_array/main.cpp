#include <iostream>
#include "circulararray.h"
#include "tester.h"

using namespace std;

void t1(), t2();

int main() {

    CircularArray<int>* array = new CircularArray<int>(7);
    // ASSERT(array->is_empty() == true, "The function is_empty is not working");
    array->push_back(6);
    array->push_back(3);
    array->push_back(7);
    array->push_back(8);
    array->push_back(1);

    // ASSERT(array->is_empty() == false, "The function is_empty is not working"); 
    // ASSERT(array->is_full() == false, "The function is_full is not working");
    array->pop_front();
    array->pop_back();
    array->pop_back();
    array->pop_back();
    

       
    // array->push_front(10);
    // array->push_front(2);

    // array->push_front(15);
    // array->push_front(4);
    // ASSERT(array->to_string() == "4 15 2 10 3 7 8 ", "The function push_front is not working");
    // ASSERT(array->is_full() == true, "The function is_full is not working");
    
    cout << array->size() << endl;
    cout << array->to_string();

    // ASSERT(array->is_sorted() == false, "The function is_sorted is not working");
    // array->sort();
    // ASSERT(array->to_string() == "2 3 4 7 8 10 15 ", "The function sort is not working");
    // array->reverse();
    // ASSERT(array->to_string() == "15 10 8 7 4 3 2 ", "The function reverse is not working");   
    delete array;       // ! possibly SEGFAULT


    // t1();
    // t2();


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