#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

template <class T>
class CircularArray
{
protected:
    T *array = nullptr;           // for runtime resizing
    int size_ = 0;
    int capacity;       // for table doubling
    int back, front;    // indirection markers
public:
    CircularArray(){
        array = new T[size_];
        capacity = 0;
        back, front = 0;
    };
    CircularArray(int _capacity){
        array = new T[size_];
        capacity = _capacity;
        back, front = 0;
    };
    
    virtual ~CircularArray(){
        delete[] array;
    };


    void push_front(T data){
        if(!is_full()){
            
            front = prev(front);
            array[front] = data;
            size_++;
        }
        else {
            resize(capacity*2);
            push_front(data);
        }

    };

    void push_back(T data){
        if(!is_full()){
            array[back] = data;
            back = next(back);
            size_++;
        } else{
            resize(capacity*2);
            push_back(data);}
    };

    void insert(T data, int pos);

    T pop_front(){
        if(!is_empty()){
            T aux = array[front];
            front = next(front);
            size_--;
            return aux;
        }
        return T();
    };

    T pop_back(){
        if(!is_empty()){
            back = prev(back);
            T aux = array[back];
            size_--;
            return aux;
        }
       return T();
    };
    
    bool is_full(){
        return next(back) == front;
    };
    bool is_empty(){
        return size_ == 0;
    };
    int size(){
        return size_;
    };
    
    void resize(int new_capacity){
        if(new_capacity > capacity){
            T* new_array = new T[new_capacity];
            int aux = front;
            for (int i = 0; i < size_; i++){
                new_array[i] = array[aux];
                aux = next(aux);
            }
            delete [] array;
            array = new_array;
            front = 0;
            back = size_;
            capacity = new_capacity;
        }
    };


    void clear();
    T &operator[](int index);
    void sort();
    bool is_sorted();
    void reverse();

    string to_string(string sep = " ") {
        string result;

        cout << "\t" << this->front << " " << this->back << endl;
        int idx = front;
        for (int i = 0; i < size_; i++) {
            if (i > 0) {
                result += sep;
            }
            result += std::to_string(array[idx]);
            idx = next(idx);
        }
        return result;
    }
       
    
    T front_() { return array[this->front]; }
    T back_() { return array[this->back]; }

private:
    // ? use modulus %
    int next(int i){
        return (i + 1) % capacity; // (front+1) % capacity
    };      

    int prev(int i){
        return (i - 1 + capacity) % capacity;
    };      // 
};

