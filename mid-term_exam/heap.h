#include <iostream>
using namespace std;

const int MAXN = 100000;

class Heap {
    public:
        void insert(int x); // Insert x in the heap
        void build(int A[], int n); // Build heap from array of n elements
        int remove_min(); // Remove and return min element in heap
        int find_min(); // Return min element in the heap
        void update(int idx, int x); // updates H[idx] to x
        void display(); // displays the heap
        void max_heapify(int A[], int idx); // Helper function
        void build_max_heap(int A[], int n); // Helper funciton
        void heap_sort(int A[], int n); // Sorting algorithm
    public:
        int H[MAXN]; // array representing heap
        int size; // size of heap
        int left(int idx); // left child
        int right(int idx); // right child
        int parent(int idx); // parent
        void min_heap_up(int idx); // Helper function
        void min_heap_down(int idx); // Helper funciton
        
};

int Heap::left(int idx){ return idx << 1; }
int Heap::right(int idx){ return (idx << 1) | 1; }
int Heap::parent(int idx){ return idx >> 1; }


int Heap::find_min(){
    return H[1];
}

int Heap::remove_min(){
    int ans = H[1];
    H[1] = H[size--];
    min_heap_down(1);
    return ans;
}

void Heap::insert(int x){
    H[++size] = x;
    min_heap_up(size);
}

void Heap::build(int A[], int n){
    copy(A, A + n, H + 1);
    size = n;
    for (int i = (size >> 1); i >= 1; --i){
        min_heap_down(i);
    }
}

void Heap::min_heap_up(int idx){
    int i = idx;
    int j = parent(i);
    while(j >= 1 && H[i] < H[j]){
        swap(H[i],H[j]);
        i = j;
        j = parent(i);
    }
}

void Heap::min_heap_down(int idx){
    int l = left(idx);
    int r = right(idx);
    int i = idx;
    int lowest = idx;
    while(l <= size){
        if( H[l] < H[lowest] )
            lowest = l;
        if( r <= size && H[r] < H[lowest] )
            lowest = r;
        if( i == lowest ) break; // heap condition is satisfied
        swap( H[i], H[lowest] );
        i = lowest;
        l = left(i);
        r = right(i);
        lowest = i;
    }
}

void Heap::update(int idx, int x){
    if( idx < 1 || idx > size ) return; // index out of bounds
    if( H[idx] < x){
        H[idx] = x;
        min_heap_down( idx );
    }
    else if( H[idx] > x){
        min_heap_up( idx );
    }
}


void Heap::display()
    {
        for (size_t i = 1; i <= size; i++)
        {
            cout << H[i] << " ";
        }
        cout << '\n';
    }

void Heap::max_heapify(int A[], int idx){ // idx = 1
    // cout << "inside" << endl; 
    int largest = idx; // largest = 1
    int l = left(idx); // l = 0
    int r = right(idx);// r = 0
    // if left child is larger than root
    // cout << "l: " << l << ", " << "size: " << size << ", " << "A[l]: " << A[l] << " > " << "A[idx]: " << A[idx] << endl;
    if(l <= size && A[l] > A[idx]){ // 0 <= 3 && 1 > 5
        // cout << "\tif1" << endl;
        largest = l;
    }

    else 
        largest = idx;

    // cout << "r: " << r << " < size: " << size << " && " << "A[r] " << A[r] << "> A[largest] "<< A[largest] << endl;
    if( r <= size && A[r] > A[largest]){

        // cout << "\tif2" << endl;
        largest = r;
    }

    if (largest != idx){
        // cout << "\tif3" << endl;
        swap(A[idx], A[largest]);
        // cout << "swap " << A[idx] << " with " << A[largest] << endl;
        max_heapify(A, largest);
    }

}

void Heap::build_max_heap(int A[], int n){
    copy(A, A + n, H + 1);
    size = n;
    
    for (int i = (size >> 1); i >= 1; --i){ // i = 3
        // cout << "\ti: " << i <<endl;
        max_heapify(H, i); // H, 1
    }
}



