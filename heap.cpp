#include <iostream>
using namespace std;

const int MAXN = 100000;


class Heap {

public:

    void insert (int x); // Insert x in the heap
    void build ( int A[] , int n); // Build heap from array of n elements
    int remove_min ( ) ; // Remove and return min element in heap
    int find_min () ; //Return min element in heap
    
private:

    
    int H[MAXN] ; // array representing heap
    int size; // size of heap
    int left( int idx ); // left child
    int right( int idx ); // right child
    int parent( int idx ); // parent
    void min_heap_up( int idx ); // Helper function
    void min_heap_down( int idx ); // Helper function


};



int main(){

    Heap h1;

    


    return 0;
}