#include <iostream>
#include <ctime>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void counting_sort(int arr[], int size, int pos) {
    int *out = new int[size]; 
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        out[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }


    for (int i = 0; i < size; i++) {
        arr[i] = out[i];
    }

    delete[] out;
}

void radix_sort(int arr[], int size)
{

    int m = getMax(arr, size);

    for (int pos = 1; m / pos > 0; pos *= 10) {
        counting_sort(arr, size, pos);
    }
}

int main() {
    srand(time(0));
    
    int sizes[] = {1000, 10000, 100000, 10000000};

    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int *arr = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000000; 
        }

        clock_t start = clock();
        radix_sort(arr, n);
        clock_t end = clock();
        
        cout << "Sorted " << n << " elements in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

        // for (int i = 0; i < n; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        delete[] arr; 
    }

    return 0;
}
