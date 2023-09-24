#include <iostream>
using namespace std;
 
void quicksort(int arr[], int p, int r), print_arr(int arr[], int size);
int partition(int arr[], int p, int r);

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
    
    //? Quicksort:
    //! worst-case running time of O(n^2), but it's expected running time is O(n lg n)
    //! Applies divide-and-conquer method

    
    int a[10] = {9, 8, 7, 2, 5, 7, 15, 35, 34, 11};

    print_arr(a, 10);

    quicksort(a, 0, 9);

    print_arr(a, 10);

}

void quicksort(int arr[], int p, int r){
    if(p < r)
    {   
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1); // recursively sort the low side
        quicksort(arr, q + 1, r); // recursively sort the high side
    }
}

int partition(int arr[], int p, int r){

    int x = arr[r]; // setting the pivot
    int i = p - 1;  // hightest index into the low side

    for (size_t j = p; j <= r - 1; ++j) // process each element other than the pivot
    {      
        // cout << "j: " << j << endl;
        // cout << "p: " << p << endl;
        // cout << "r: " << r << endl;
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