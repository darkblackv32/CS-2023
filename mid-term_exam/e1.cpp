#include "heap.h"
using namespace std;
 
void quicksort(int arr[], int p, int r), print_arr(int arr[], int size);
size_t partition(int arr[], int p, int r);

void q1(), q2(), q3(), q4();


int main(){

    q1();
    // q2();
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


















void quicksort(int arr[], int p, int r){
    if(p < r)
    {   
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1); // recursively sort the low side
        quicksort(arr, q + 1, r); // recursively sort the high side
    }
}

size_t partition(int arr[], int p, int r){

    int x = arr[r]; // setting the pivot
    int i = p - 1;  // hightest index into the low side

    for (size_t j = p; j <= r - 1; ++j) // process each element other than the pivot
    {      
        if(arr[j] <= x) // odes this element belong on the low side?
        {   
            i++; // index of a new slot in the low slide
            swap(arr[i], arr[j]); // put this element there
        } 
    }

    swap(arr[i+1], arr[r]); // pivot goes just to the right of the low side
    return i + 1; // new index of the pivot
}


void print_arr(int arr[], int size){

    for (size_t i = 0; i < size; i++)
    {   
        cout << arr[i] << " ";
    }
    
    cout << '\n';
}