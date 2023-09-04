#include <iostream>
using namespace  std;

template <class T>
class ArrayIterator
{
private:
    int current;
    T* array;
    
public:
    ArrayIterator(){
        current = 0;
        this->array = nullptr;
    }

    ArrayIterator(int index, T* array){
        this->current = index;    
        this->array = array;
    }

    bool operator != (const ArrayIterator &other){
        return this->current != other.current;
    }

    ArrayIterator& operator++(){
        ++this->current;
        return *this;
    }

    ArrayIterator& operator--(){
        --this->current;
        return *this;
    }
    
    T& operator*(){
        return this->array[this->current];
    }
};

template <class T>
class Array
{
   
public:
    typedef ArrayIterator<T> iterator;

    iterator begin(){
        return iterator(0, this->array);
    }

    iterator end(){
        return iterator(this->nsize, this->array);
    }
    
private:
    T* array;
    int capacity;
    int nsize;
public:
    Array();
    Array(int _capacity);
    virtual ~Array();    
    void push_back(T data);        
    T pop_back();    
    int size();
    void display();      
};

template <class T>
Array<T>::Array()
{
    Array(10);
}

template <class T>
Array<T>::Array(int _capacity)
{
    this->capacity = _capacity;
    this->nsize = 0;
    this->array = new T[_capacity];
}

template <class T>
Array<T>::~Array()
{ 
    delete[] array;
}

template <class T>
int Array<T>::size()
{
    return this->nsize;
}


template <class T>
void Array<T>::push_back(T data)
{
    if(this->nsize >= this->capacity) throw "The array is full";    
    array[this->nsize++] = data;
}

template <class T>
T Array<T>::pop_back()
{
    if(this->nsize <= 0) throw "The array is empty";    
    return array[this->nsize--];
}

template <class T>
void Array<T>::display()
{    
    for (int i = 0; i < nsize; i++)
        cout<<array[i]<<",";        
    cout<<endl;
}




