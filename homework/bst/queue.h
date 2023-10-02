#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T>
{
public:
    QueueArray(int _capacity = 10) : CircularArray<T>(_capacity) {}

    void enqueue(T data)
    {
        if (this->is_full())
        {
            this->resize(this->capacity * 2);
        }
        this->push_back(data);
    }

    T dequeue()
    {
        if (this->is_empty())
        {
            throw runtime_error("Stack is empty");
        }
        return this->pop_front();
    }

    string to_string(string sep = " ")
    {
        return this->CircularArray<T>::to_string(sep);
    }
};