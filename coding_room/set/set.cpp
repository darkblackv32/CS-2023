#include <iostream>
#include "set.h"
using namespace std;

int main()
{
    Set<int> myset;//basado en hash
    myset.insert(15); myset.insert(20); myset.insert(5); myset.insert(10); myset.insert(20);
    myset.insert(155); myset.insert(204); myset.insert(53); myset.insert(110); myset.insert(202);
    myset.insert(5);
    myset.display();//5,10,20,15
    cout<< myset.contains(10)<<endl;
    cout<< myset.contains(204)<<endl;
    cout<< myset.contains(999)<<endl;
    Set<int> myset2;
    myset2.insert(5);myset2.insert(10);myset2.insert(8);myset2.insert(25);
    Set<int> myset3 = myset.Union(myset2); //O(n)
    myset3.display();//5,10,20,15,8,25
}
