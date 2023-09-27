#include <iostream>
#include <initializer_list>

using namespace std;

template<typename T>
class Array;

template<typename T>
void make_heap(Array<T> &myarray);

template<typename T>
class Array
{
  public:
    T* array;
    int size;
    int capacity;

  public:
      Array(initializer_list<T> lista){
          capacity = 2*lista.size();
          array = new T[capacity];
          size = 0;
          for(auto elem : lista){
              array[size++] = elem;
          }
      }

    void push_back(T value){
        array[size++] = value;
    }    

    T& operator[](int pos){
        return array[pos];
    }

    void display(){
        for(int i=0;i<size;i++)
             cout<<array[i]<<",";
         cout<<endl;
    }

    friend void make_heap<>(Array<T> &myarray);

};

//implementar el heap


template<typename T>
void make_heap(Array<T> &myarray) {
    for (int i = myarray.size / 2 - 1; i >= 0; --i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int lowest = i;

        if (left < myarray.size && myarray[left] < myarray[lowest]) {
            lowest = left;
        }

        if (right < myarray.size && myarray[right] < myarray[lowest]) {
            lowest = right;
        }

        if (lowest != i) {
            swap(myarray[i], myarray[lowest]);
            make_heap(myarray);
        }
    }
}



template<typename T>
void heap_push(Array<T> &myarray, T value)
{
    myarray.push_back(value); 

    int i = myarray.size - 1; 
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (myarray[i] < myarray[parent]) {
            swap(myarray[i], myarray[parent]);
            i = parent;
        } else {
            break; 
        }
    }
}


template<typename T>
void heap_pop(Array<T> &myarray){
    if (myarray.size == 0) {
        return; 
    }

    swap(myarray[0], myarray[myarray.size - 1]);
    --myarray.size;

    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int lowest = i;

        if (left < myarray.size && myarray[left] < myarray[lowest]) {
            lowest = left;
        }

        if (right < myarray.size && myarray[right] < myarray[lowest]) {
            lowest = right;
        }

        if (lowest != i) {
            swap(myarray[i], myarray[lowest]);
            i = lowest;
        } else {
            break;
        }
    }
}

template<typename T>
void heap_sort(Array<T> &myarray){
    make_heap(myarray);

    for (int i = myarray.size - 1; i > 0; --i) {
        swap(myarray[0], myarray[i]); 

        for (int j = 0; j < i / 2;) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int lowest = j;

            if (left < i && myarray[left] < myarray[lowest]) {
                lowest = left;
            }

            if (right < i && myarray[right] < myarray[lowest]) {
                lowest = right;
            }

            if (lowest != j) {
                swap(myarray[j], myarray[lowest]);
                j = lowest;
            } else {
                break; 
            }
        }
    }
}

