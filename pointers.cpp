#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // POINTER: a variable that stores the memory address of another variable as its value.
    // VALUE: value of the variable
    //   &: ampersand operator -> return the memory address of the variable
    //  &&: and (conditional)
    //  &: logical operations

    int a = 5;
    int* b = &a;
    int** c = &b;
    int*** d = &c;

    cout << " a:   " << a << endl;      // VALUE: 5
    cout << "&a:   " << &a << endl;     // a memory address (ampersand operator)
    cout << " b:   " << b << endl;      // VALUE: a memory address
    cout << "&b:   " << &b << endl;     // pointer b memory address
    cout << " c:   " << c << endl;      // c stores the memory address of b

    cout << "*b:   " << *b << endl;     // a value: 5
    cout << "&*b:  " << &*b << endl;    // a memory address
    
    cout << "*c:   " << *c << endl;       // b value : a memory address
    cout << "**c:  "<< **c << endl;      // a value: 5
    cout << "&**c: "<< &**c << endl;    // a memory address
    

    cout << boolalpha;      // true false
    /*
        b = int*        int pointer
        &b = int**      pointer to int pointer
    */
    // cout << (b == &b) << endl;      // false
    cout << (*b == a) << endl;      // true
    cout << (&a == &*b) << endl;    // true
}

/*
address       |   variable    |   value
------------------------------------------
0x7ffe7cca3ed4          a               5
0x7ffe7cca3ed8          b           0x7ffe7cca3ed4
0x7ffe7cca3edb          c           0x7ffe7cca3ed8
------------------------------------------

*address = value of the address

b = 0x7ffe7cca3ed4
*b = *(0x7ffe7cca3ed4) = a = 5

c = 0x7ffe7cca3ed8
*c = *(0x7ffe7cca3ed8) b = 0x7ffe7cca3ed8       (a address)
*/