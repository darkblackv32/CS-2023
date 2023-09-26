#include <iostream>
#include <forward_list>

using namespace std;

const int MAX_COLISION = 3;

template<typename TK>

class Set
{
private:
    forward_list<TK> *array;
    int capacity;
    int size;

    size_t getHashCode(TK key) {
        hash<TK> ptr_hash;
        return ptr_hash(key);
    }

    void rehashing() {
        int old_capacity = capacity;
        capacity *= 2;
        forward_list<TK> *newArray = new forward_list<TK>[capacity];

        for(int i = 0; i < old_capacity; i++) {
            for(auto &key: array[i]) {
                size_t hashcode = getHashCode(key);
                int index = hashcode % capacity;
                newArray[index].push_front(key);
            }
        }
        delete[] array;
        array = newArray;
    }

public:

    Set(int _cap = 4) {
        capacity = _cap; 
        array = new forward_list<TK>[capacity];
        size = 0;
    }

    ~Set() {
        delete[] array;
    }

    void insert(TK key) {    
        size_t hashcode = getHashCode(key);
        int index = hashcode % capacity;
        int num_colision = 0;   
        bool existe = false;  
        for(auto ite = array[index].begin(); ite != array[index].end(); ++ite) {
            if(*ite == key){
                existe = true;
                break;
            }
            ++num_colision;
        }
        if(!existe) {
            array[index].push_front(key);
            ++size;
            if(num_colision == MAX_COLISION) rehashing();
        }
    }

    bool contains(TK key) {
        size_t hashcode = getHashCode(key);
        int index = hashcode % capacity;
        for(auto ite = array[index].begin(); ite != array[index].end(); ++ite) {
            if(*ite == key) {
                return true;
            }
        }
        return false;
    }

    Set Union(const Set<TK> &otro) {
        Set result;
        for(int i = 0; i < capacity; i++) {
            for(auto &key: array[i]) {
                result.insert(key);
            }
        }
        for(int i = 0; i < otro.capacity; i++) {
            for(auto &key: otro.array[i]) {
                result.insert(key);
            }
        }
        return result;
    }

    void display() {
        for(int i = 0; i < capacity; i++) {
            for(auto &key: array[i]) {
                cout << key << ", ";
            }
        }
        cout << endl;
    }
};