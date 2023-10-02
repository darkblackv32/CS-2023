#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T>
{
private:
public:
    StackArray(){};

    StackArray(int _capacity)
    {
        this->capacity = _capacity;
        this->array = new T[_capacity];
        this->front = this->back = -1; // empty
    }

    void push(T data)
    {
        if (this->is_full())
        {
            this->resize(this->capacity * 2);
        }
        this->push_back(data);
    }

    bool empty()
    {
        return this->is_empty();
    }

    T top()
    {
        if (this->is_empty())
        {
            throw runtime_error("Stack is empty");
        }
        return this->back_();
    }

    T pop()
    {
        if (this->is_empty())
        {
            throw runtime_error("Stack is empty");
        }
        return this->pop_back();
    }

    string to_string(string sep = " ")
    {
        return this->CircularArray<T>::to_string(sep);
    }
};