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
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();

    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    
    bool is_full();
    bool is_empty();
    int size();
    
    void resize(int new_capacity);
    void clear();
    T &operator[](int index);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");       // overload << operator
    
    T front_() { return array[this->front]; }
    T back_() { return array[this->back]; }
private:
    // ? use modulus %
    int next(int);      // (front+1) % capacity
    int prev(int);      // 
};
