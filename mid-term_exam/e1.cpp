#include "heap.h"
#include "bst.h"
#include "q1.h"
// #include "q2.h"

using namespace std;
 
void q1(), q2(), q3(), q4();


int main(){

    // q1();
    q2();
    // q3();
    // q4();

}


void q1()
{
    
    //* Make a comparison between QuickSort and HeapSort algorithms. (advantages, disadvantages, complexity)
    
    //* Quicksort:
    //! worst-case running time of O(n^2), but it's expected running time is O(n lg n)
    //! since each recursive call requires a constant amount of space on the runtime stack, outside of the array being sorted,  quicksort requires space proportional
    //!  to the maximun depth of the recursion, and that could be as bad as O(n) in the worst case
    //! applies divide-and-conquer method

    /* advantages:
        * in-place sorting: it doesn't require additional memory proportional to the input size, it onlu needs a small amount of auxiliary memory for recursion
        * efficient average case: O(nlogn), highly efficient.
        * fast for random data
    
    */

    /* disadvantages:
        * the O(n^2) running time occurs when the input array is already completely sorted, situation in which insertion sort runs in O(n) time
        * their efficiency heavily relies on the choice of the pivot element
        * not suitable for linked lists due to ist random access nature 
    
    */

    int a[10] = {9, 8, 7, 2, 5, 7, 15, 11, 34, 1};

    print_arr(a, 10);

    quicksort(a, 0, 9);

    print_arr(a, 10);


    //* Heapsort:
    //! The heapsort procedure takes O(n lg n), since the call to build-max-heap takes O(n) time and each of the n - 1 calls to max_heapify takes O(lg n) time.
   

   //? advantages
   //* time complexity of O(n lg n) in all the cases 
   //* quite easy to understand and simple to implement if you have the max-heap class
   //* highly consistent with very low memory usage, no extra memory space is required to work, unlike merge_sort or recursive quick_sort
    
    //? disadvantages
    //* unstable sort, doesn't mantains the relative order of item that have the same key
    //* inefficient when dealing with highly complex data


    int A[] = {5, 1, 77, 2, 89, 1, 999};
    int n = sizeof(A) / sizeof(A[0]);

    Heap h1;

    h1.heap_sort(A, n);
    
}

void q2(){
    
    //* There are five ways to print a BST, two of them have the same order, write the name of both and describe how they traverse the tree 
   
   //? answer: PreOrder and Depth First Search Order

    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.pre_or_display();
    t.dfs_display();
 
}

void q3(){
    
}