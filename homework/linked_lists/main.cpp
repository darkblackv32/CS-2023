#include <iostream>
#include "tester.h"
#include "forward.h"
#include "double.h"
#include "circular.h"

#include <iomanip>

template<typename T>
void preTest(List<T>* list)
{
    std::cout << std::boolalpha << list->is_empty() << std::endl;
    std::cout << list->size() << std::endl;

    list->push_front(5);        // 5
    list->display();
    list->push_front(10);       // 10 5
    list->display();
    list->insert(15, 2);        // 10 5 15
    list->display();

    list->pop_front();          // 5 15
    list->display();

    list->push_back(20);        // 5 15 20
    list->push_back(15);        // 5 15 20 15
    list->pop_back();           // 5 15 20
    list->display();

    list->push_back(30);        // 5 15 20 30
    list->push_back(8);         // 5 15 20 30 8
    list->insert(12, 2);        // 5 15 12 20 30 8
    list->display();

    std::cout << "\nREVERSE: ";
    list->reverse();            // 8 30 20 12 15 5
    list->display();

    std::cout << "\nSORT\n";
    std::cout << list->size() << " -> ";
    list->sort();               // 5 8 12 15 20 30
    list->display();


    std::cout << "\nREMOVE: \n";
    list->remove(3);            // 5 8 12 20 30
    list->remove(0);            // 8 12 20 30
    list->remove(3);            // 8 12 20
    list->display();

    std::cout << "CLEAR: \n";
    list->clear();
    list->display();

}

template<typename T>
void preTest_2(List<T>* list)
{
    list->push_back(5);
    list->display();        // 5
    std::cout << "back: " << list->back() << std::endl;     // 5

    T i = 10;
    while(i--)
    {
        if (i&1) list->push_back(i);
        else list->push_front(i);
    }
    list->display();            // 0 2 4 6 8 5 9 7 5 3 1
    std::cout << list->size() << std::endl;     // 11

    std::cout << "front: " << list->front() << std::endl;       // 0
    std::cout << "back: " << list->back() << std::endl;         // 1
    std::cout << " reversa:\n";
    list->reverse();
    list->display();        //  1 3 5 7 9 5 8 6 4 2 0
    list->insert(18, 5);
    list->display();        // 1 3 5 7 9 18 5 8 6 4 2 0

    std::cout << " *"<< (*list)[5] << std::endl;
    std::cout << (*list)[0] << std::endl;
    std::cout << (*list)[11] << std::endl;
    list->display();
    std::cout << " ------------------ SORT \n";
    list->sort();
    list->display();
    list->clear();
    list->display();
}


void test(List<int>* list){
    ASSERT(list->is_empty() == true, "The function is_empty is not working");               // 1
    ASSERT(list->size() == 0, "The function is_full is not working");                       // 2
    list->push_front(5);
    list->push_front(10);
    ASSERT(list->pop_front() == 10, "The function push_front/pop_front is not working");    // 3
    list->push_back(20);
    list->push_back(15);
    ASSERT(list->pop_back() == 15, "The function push_back/pop_back is not working");       // 4
    list->push_back(30);
    list->push_back(8);
    list->insert(12, 2);
    ASSERT((*list)[2] == 12, "The operator [] is not working");                             // 5
    list->push_back(10);
    list->push_front(3);

    ASSERT(list->is_sorted() == false, "The function sort is not working");                 // 6
    list->sort();
    //list->display();
    ASSERT(list->is_sorted() == true, "The function sort is not working");                  // 7
    list->clear();
    ASSERT(list->is_empty() == true, "The function clear is not working");                  // 8
    delete list;
}



int main()
{
    List<int> *forward = new ForwardList<int>();
    test(forward);

    // List<int> *doble = new DoublyList<int>();
    // test(doble);

    // List<int> *circular = new CircularList<int>();
    // test(circular);
    
    return 0;
}