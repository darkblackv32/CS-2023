#include "array.h"

int main(){
    Array<int> myarray { 5, 18, 10, 6, 2, 11, 20, 34, 16, 28, 25 };    
        
    //Test 1
    make_heap(myarray);    
    myarray.display();//2,5,10,6,18,11,20,34,16,28,25
    cout<<myarray[0]<<endl;//2
    
    heap_push(myarray, 8);
    heap_push(myarray, 1);
    myarray.display();//1,5,2,6,18,8,20,34,16,28,25,11,10

    //Test 2
    heap_pop(myarray);    
    myarray.display();
    heap_sort(myarray);
    myarray.display();
}   