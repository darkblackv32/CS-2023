#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

template <class T>
class CircularArray
{
protected:
    T *array = nullptr;           // for runtime resizing
    int size_ = 0;      // # elementos actuales
    int capacity;       // # espacios separados en memoria | for table doubling
    int back, front;    // indirection markers
public:
    CircularArray(){
        array = new T[size_];
        capacity = size_;
        back, front = 0;
    };
    
    CircularArray(int _capacity){
        // cout << __PRETTY_FUNCTION__ << " -> " << size_ << endl;
        capacity = _capacity;
        array = new T[capacity];       // ? new int[0];
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
        if(!is_empty())
        {
            T aux = array[front];
            front = next(front);
            size_--;
            return aux;
        }
        return T();
    };

    T pop_back(){
        if(!is_empty())
        {
            back = prev(back);
            T aux = array[back];
            size_--;
            return aux;
        }
        // else cerr/throw
        

        // if (size_ < capacity/2)
        //     resize(capacity/2);
        return T();
    };
    
    bool is_full(){
        return size_ == capacity;       // back == front && 
    };

    bool is_empty(){
        return size_ == 0;
    };

    int size(){
        return size_;
    };
    
    void resize(int new_capacity)
    {
        if(new_capacity > capacity)
        {
            T* new_array = new T[new_capacity];
            int aux = front;
            for (int i = 0; i < size_; i++)
            {
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

        // cout << "\tmarcadores: " << this->front << " " << this->back << endl;
        int idx = front;
        for (int i = 0; i < size_; i++) {
            result += std::to_string(array[idx]);
            result += sep;
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

