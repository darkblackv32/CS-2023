#include <iostream>
#include "bst.h"

using namespace std;

int main(){
    AVLTree<int> *avl = new AVLTree<int>();
    avl->insert(35);
    avl->insert(30);
    avl->insert(27);
    avl->insert(11);
    avl->insert(16);
    avl->insert(100);
    avl->insert(50);
    avl->insert(91);
    avl->insert(73);
    avl->insert(5);
    avl->displayPreOrder();//30, 16, 11, 5, 27, 50, 35, 91, 73, 100, 
    cout<<endl<<avl->height()<<endl;//3
    avl->displayPretty();
}