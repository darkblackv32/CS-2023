

void quicksort(int arr[], int p, int r), print_arr(int arr[], int size);
size_t partition(int arr[], int p, int r);


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