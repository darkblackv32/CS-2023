#include <iostream>
#pragma once

using namespace std;

template <class T>
class CircularArray
{
protected:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray(int _capacity = 10); // implemented
    virtual ~CircularArray();          // implemented
    void push_front(T data);           // implemented
    void push_back(T data);            // implemented
    void insert(T data, int pos);      // implemented
    T pop_front();                     // implemented
    T pop_back();                      // implemented
    bool is_full();                    // implemented
    bool is_empty();                   // implemented
    int size();                        // implemented
    void clear();                      // implemented
    T back_();                         // implemented
    T &operator[](int pos);            // implemented
    void sort();                       // implemented
    bool is_sorted();                  // implemented
    void reverse();                    // implemented
    string to_string(string sep = " ") // implemented
    {
        string result;
        int size_ = size();
        // cout << "\tmarcadores: " << this->front << " " << this->back << endl;
        int idx = front;
        for (int i = 0; i < size_; i++)
        {
            result += std::to_string(array[idx]);
            result += sep;
            idx = next(idx);
        }
        return result;
    }

protected:
    int next(int);                 // implemented
    int prev(int);                 // implemented
    void resize(int new_capacity); // implemented
};

template <class T>
int CircularArray<T>::next(int i)
{
    return (i + 1) % this->capacity;
}

template <class T>
int CircularArray<T>::prev(int i)
{
    return (i - 1 + this->capacity) % this->capacity;
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1; // empty
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] this->array;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return this->front == this->next(this->back);
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return this->front == -1 or this->back == -1;
}

template <class T>
int CircularArray<T>::size()
{
    if (is_empty())
    {
        return 0;
    }
    else if (this->front <= this->back)
    {
        return this->back - this->front + 1;
    }
    else
    {
        return this->capacity - this->front + this->back + 1;
    }
}

template <class T>
void CircularArray<T>::clear()
{
    this->front = this->back = -1;
    resize(5);
}

template <class T>
void CircularArray<T>::resize(int new_capacity)
{
    T *new_array = new T[new_capacity];
    int j = 0;

    // cout << "Redimensionando..." << endl;

    if (!this->is_empty())
    {
        if (capacity <= new_capacity)
        {
            int e = this->front;
            for (int i = 0; i < this->size(); i++)
            {
                // cout << "   - Insertando en el nuevo array la posicion " << j << " el elemento " << this->array[e] << endl;
                new_array[j++] = this->array[e];
                e = this->next(e);
            }
        }
        else
        {
            int e = this->front;
            for (int i = 0; i < new_capacity; i++)
            {
                new_array[j++] = this->array[e];
                e = this->next(e);
            }
        }
    }

    delete[] this->array;
    this->array = new_array;

    if (this->back != -1 and this->front != -1)
    {
        this->front = 0;
        this->back = j - 1;
    }
    this->capacity = new_capacity;

    /*
    cout << "Resized to " << this->capacity << endl;
    cout << "N of elements: " << this->size() << endl;
    cout << "Front: " << this->front << endl;
    cout << "Back: " << this->back << endl;
    */
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if (is_full())
    {
        resize(this->capacity * 2);
        push_back(data);
    }
    else if (is_empty())
    {
        this->front = this->back = 0;
        this->array[this->back] = data;
        // cout << "Acabo de pushear " << data << " en la posicion " << this->back << endl;
    }
    else
    {
        this->back = this->next(this->back);
        this->array[this->back] = data;
        // cout << "Acabo de pushear " << data << " en la posicion " << this->back << endl;
    }
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if (is_full())
    {
        resize(this->capacity * 2);
        push_front(data);
    }
    else if (is_empty())
    {
        this->front = this->back = 0;
        this->array[this->front] = data;
        // cout << "Acabo de frontear " << data << " en la posicion " << this->front << endl;
    }
    else
    {
        this->front = this->prev(this->front);
        this->array[this->front] = data;
        // cout << "Acabo de frontear " << data << " en la posicion " << this->front << endl;
    }
}

template <class T>
T CircularArray<T>::pop_front()
{
    if (is_empty())
    {
        throw "Arreglo vacio";
    }
    else if (this->front == this->back)
    {
        T data = this->array[this->front];
        this->front = this->back = -1;
        // cout << "El array esta vacio. Redimencionando a 5." << endl;
        this->resize(5);
        return data;
    }
    else
    {
        T data = this->array[this->front];
        this->front = this->next(this->front);
        // cout << "Acabo de popfrontear " << data << " en la posicion " << this->front << endl;
        return data;
    }
}

template <class T>
T CircularArray<T>::pop_back()
{
    if (is_empty())
    {
        throw "Arreglo vacio";
    }
    else if (this->front == this->back)
    {
        T data = this->array[this->back];
        this->front = this->back = -1;
        // cout << "El array esta vacio. Redimencionando a 5." << endl;
        this->resize(5);
        return data;
    }
    else
    {
        T data = this->array[this->back];
        this->back = this->prev(this->back);
        // cout << "Acabo de popbackear " << data << " en la posicion " << this->back << endl;
        return data;
    }
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    if (is_full())
    {
        resize(this->capacity * 2);
        insert(data, pos);
    }
    else if (is_empty())
    {
        this->front = this->back = 0;
        this->array[this->front] = data;
        // cout << "Acabo de insertar " << data << " en la posicion " << this->front << endl;
    }
    else
    {
        if (pos == 0)
        {
            push_front(data);
        }
        else if (pos == this->size())
        {
            push_back(data);
        }
        else
        {
            int e = this->front;
            for (int i = 0; i < pos; i++)
            {
                e = this->next(e);
            }
            this->back = this->next(this->back);
            for (int i = this->back; i > e; i--)
            {
                this->array[i] = this->array[i - 1];
            }
            this->array[e] = data;
            // cout << "Acabo de insertar " << data << " en la posicion " << e << endl;
        }
    }
}

template <class T>
T &CircularArray<T>::operator[](int pos)
{
    if (pos < 0 or pos >= this->size())
    {
        throw "Posicion invalida";
    }
    else
    {
        int e = this->front;
        for (int i = 0; i < pos; i++)
        {
            e = this->next(e);
        }
        return this->array[e];
    }
}

template <class T>
T CircularArray<T>::back_()
{
    if (is_empty())
    {
        throw "Arreglo vacio";
    }
    else
    {
        return this->array[this->back];
    }
}

template <class T>
void CircularArray<T>::sort()
{
    int e = front;
    int max = array[e];

    for (int i = 0; i < size(); i++)
    {
        if (array[e] > max)
        {
            max = array[e];
        }
        e = next(e);
    }

    int *count = new int[max + 1];
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    e = front;
    for (int i = 0; i < size(); i++)
    {
        ++count[array[e]];
        e = next(e);
    }

    int index = front;
    for (int i = 0; i <= max; ++i)
    {
        for (int j = 0; j < count[i]; ++j)
        {
            array[index] = i;
            index = next(index);
        }
    }

    delete[] count;
}

template <class T>
bool CircularArray<T>::is_sorted()
{
    int e = front;
    for (int i = 0; i < size() - 1; i++)
    {
        if (array[e] > array[next(e)])
        {
            return false;
        }
        e = next(e);
    }
    return true;
}

template <class T>
void CircularArray<T>::reverse()
{
    int e = front;
    int *temp = new int[size()];
    for (int i = 0; i < size(); i++)
    {
        temp[i] = array[e];
        e = next(e);
    }
    e = front;
    for (int i = size() - 1; i >= 0; i--)
    {
        array[e] = temp[i];
        e = next(e);
    }
    delete[] temp;
}