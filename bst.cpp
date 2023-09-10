#include <iostream>
using namespace std;

// a binary tree is a tree in which no node can have more than two children
// the average value of the depth is O(log N). Unfortunately, the depth can be as large as N − 1




/* The property that makes a binary tree into a binary search tree is that for every node,
X, in the tree, the values of all the items in its left subtree are smaller than the item in X,
and the values of all the items in its right subtree are larger than the item in X. */

/* Because the average depth of a binary search tree turns out to be
O(log N), we generally do not need to worry about running out of stack space.*/

template <typename T>
class BST
{

public:

    BST() = default;
    ~BST();

    const T& findMin() const;
    const T& findMax() const;
    bool contains(const T& x) const;
    bool isEmpty() const;
    void printTree(ostream& out = cout) const;

    void makeEmpty();
    void insert(const T& x);
    void remove(const T& x);

private:

    struct Node{

        T element;  // data
        Node *left; // left child
        Node *right; // right child

        Node() = default;
        Node(const T& el, Node *lft, Node *rgt) : element{el}, left{lft}, right{rgt}{}

    };

    Node *root;

    void insert(const T& x, BST* &t);
    void remove(const T& x, BST* &t);
    BST* findMind(BST* t) const;
    BST* findMax(BST* t) const;
    bool contains(const T& x, BST *t) const;
    void makeEmpty(BST* &t);
    void printTree(BST *t, ostream& out) const;
    BST* clone(BST *t) const;

};

int main(){
    
    BST<int> t1; 
}