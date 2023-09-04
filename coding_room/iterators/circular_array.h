#include <iostream>
using namespace  std;


template <class T>
class CircularArrayIterator
{
private:
    int current;
    T* array;
    
public:
    CircularArrayIterator() : current(0), array(nullptr) {}

    CircularArrayIterator(int index, T* array) : current(index), array(array) {}

    bool operator != (const CircularArrayIterator &other){
        return this->current != other.current;
    }

    CircularArrayIterator& operator++(){
        ++this->current;
        return *this;
    }

    CircularArrayIterator& operator--(){
        --this->current;
        return *this;
    }
    
    T& operator*(){
        return this->array[this->current];
    }
};


template <class T>
class CircularArray
{
private:
    T* array;
    int capacity;
    int back, front;
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
    void display();
    string to_string(string sep=" ");
    void clear();
    T& operator[](int);

    class iterator
    {
    private:
        int current;
        T* array;
        int capacity; 

    public:
        iterator(int index, T* arr, int cap) : current(index), array(arr), capacity(cap) {}
        iterator() : current(0), array(nullptr), capacity(0) {}

        T& operator*()
        {
            return array[current];
        }

        // bool operator!=(const iterator& other)
        // {
        //     return current != other.current;
        // }

        bool operator!=(const iterator& other)
        {
            if (current == -1 && other.current == -1) {
                return false;
            }
            return current != other.current;
        }


        iterator& operator++()
        {
            current = (current + 1) % capacity;
            return *this;
        }
    };

    iterator begin()
    {
        return iterator(front, array, capacity);
    }

    iterator end()
    {
        return iterator((back + 1) % capacity, array, capacity);
    }

        
private:
    int next(int);
    int prev(int);    
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(10);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->front = this->back = -1;
    this->array = new T[_capacity];
}

template <class T>
CircularArray<T>::~CircularArray()
{ 
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index){    
    return (index==0)? capacity - 1: index -1;
}

template <class T>
int CircularArray<T>::next(int index){
    return (index + 1) % capacity;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return front == -1;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return front == next(back) && !is_empty();
}

template <class T>
int CircularArray<T>::size()
{
    if(is_empty()) return 0;    
    return (back>=front)? back - front + 1: capacity - front + back + 1;
}

template <class T>
T& CircularArray<T>::operator[](int pos)
{
    if(pos >= capacity) throw "index out of range";
    return array[(front + pos) % capacity];
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if(is_full()) throw "The array is full";
    if(is_empty()) front = back = 0;
    else front = prev(front);
    array[front] = data;
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if(is_full()) throw "The array is full";
    if(is_empty()) front = back = 0;
    else back = next(back);
    array[back] = data;
}

template <class T>
T CircularArray<T>::pop_front()
{
    if(is_empty()) throw "The array is empty";
    T temp = array[front];
    if(front == back) front = back = -1;
    else front = next(front);
    return temp;
}

template <class T>
T CircularArray<T>::pop_back()
{
    if(is_empty()) throw "The array is empty";
    T temp = array[back];
    if(front == back) front = back = -1;
    else back = prev(back);
    return temp;
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    int n = size();
    if(pos < 0 || pos > n) throw "index out of range";
    if(n == capacity) throw "The array is full";        
    if(pos == 0)
        push_front(data);
    else {
        for (int i = n - 1; i >= pos; i--)
            (*this)[i+1] = (*this)[i];
        (*this)[pos] = data;
        back = next(back);
    }
}

template <class T>
void CircularArray<T>::display()
{    
    for (int i = 0; i < size(); i++)
        cout<<(*this)[i]<<",";        
    cout<<endl;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = "";
    for(int i=0; i < size(); i++)
        result += std::string((*this)[i])  + sep;
    return result;
}


template <class T>
void CircularArray<T>::clear()
{
    front = back = -1;
}


