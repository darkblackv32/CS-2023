#include "hash_table.h"
#include "heap.h"
#include "bst.h"
#include "q1.h"
// #include "q2.h"

using namespace std;
 
void q1(), q2(), q3(), q4(), q5();


int main(){

    // q1();
    // q2();
    // q3();
    // q4();
    q5();

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

    // int a[10] = {9, 8, 7, 2, 5, 7, 15, 11, 34, 1};

    // print_arr(a, 10);

    // quicksort(a, 0, 9);

    // print_arr(a, 10);


    //* Heapsort:
    //! The heapsort procedure takes O(n lg n), since the call to build-max-heap takes O(n) time and each of the n - 1 calls to max_heapify takes O(lg n) time.
   

   //? advantages
   //* time complexity of O(n lg n) in all the cases 
   //* quite easy to understand and simple to implement if you have the max-heap class
   //* highly consistent with very low memory usage, no extra memory space is required to work, unlike merge_sort or recursive quick_sort
    
    //? disadvantages
    //* unstable sort, doesn't mantains the relative order of item that have the same key
    //* inefficient when dealing with highly complex data


    int A[] = {81, 14, 17, 71, 25, 80, 20, 31, 59, 16, 24, 70};
    int n = sizeof(A) / sizeof(A[0]);

    Heap h1;

    // h1.heap_sort(A, n);
    h1.build_max_heap(A, n);
    h1.display();

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

    // *We have seen two ways to handle collisions in a hash tables: open addressing and chaining. Describe the process in chaining to remove an element.
    
    // Create a hash table with 3 indices:
    HashTable ht(3);

    // Declare the data to be stored in the hash table:
    int arr[] = {87, 65, 77, 12, 37};

    for(int i = 0; i < 5; i++)
        ht.insertElement(arr[i]);

    cout << " Hash Table " << endl;
    ht.printAll();
  
    ht.removeElement(77);
    cout << endl << " After deleting 77 " << endl;
    ht.printAll();


    //* in a simple form you can think of hashing with chaining as a nonrecursive form of divide-conquer, A has function determines which subset an element belongs to.
    //* each subset is managed independently as a list, where worst-case running time for insertion and is O(1) and deletion two if the list ia doubly-linked-list 


}


void q4(){

    //? Describe in which situations it's more convenient use a BST instead of a Max_heap and vice versa



}

void q5(){

    BST t;
    t.insert(8);
    t.insert(10);
    t.insert(14);
    t.insert(13);
    t.insert(3);
    t.insert(1);
    t.insert(4);
    t.insert(7);
    t.insert(6);

    t.print_padre_dos(t.root);
        for (auto it : s1) 
        cout << it << " "; 

    // t.dfs_display();


}