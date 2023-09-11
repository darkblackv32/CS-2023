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
    ~BST()
    {
        makeEmpty();    
    }

    const T& findMin() const;
    const T& findMax() const;

    bool contains(const T& x) const
    {   
        // Returns true if x is found in the tree
        return contains(x, root);
    }

    bool isEmpty() const{
        if(root == nullptr)
            return true;
        else
            return false;
    }

    void printTree(ostream& out = cout) const;

    void makeEmpty(){
        makeEmpty(root);
    };

    void insert(const T& x)
    {
        // Insert x into the tree; duplicates are ignored
        insert(x, root);
    }


    void remove(const T& x)
    {
        // Remove x from the tree. Nothing is done if x is not found.
        remove(x, root);
    }


private:

    struct Node{

        T element;  // data
        Node *left; // left child
        Node *right; // right child

        Node() = default;
        Node(const T& el, Node *lft, Node *rgt) : element{el}, left{lft}, right{rgt}{}

    };

    Node *root;

    void insert(const T& x, Node* &t)
    {
        if (t == nullptr)
            t = new Node{x, nullptr, nullptr};

        else if(x < t->element)
            insert(x, t->left);
        
        else if(x > t->element)
            insert(x, t->right);

        else;
    }

    void remove(const T& x, Node* &t)
    {
        if(t == nullptr)
            return ;
        
        if(x < t->element)
            remove(x, t->left);
        
        else if(t->element < x)
            remove(x, t->right);
        
        else if(t->left != nullptr && t->right != nullptr) // two children
        { 
            t->element = findMin(t->right)->element;
            remove(t->element,t->right);
        }

        else
        {
            Node *oldNode = t;
            t = (t->left != nullptr) ? t->left : t-> right;
            delete oldNode;    
        }

        } 
    

    Node* findMin(Node* t) const
    {
        if(t == nullptr)
            return nullptr;

        if(t->left == nullptr)
            return t;

        return findMin(t->left);
    }

    Node* findMax(Node* t) const{
        
        if(t != nullptr)
            while(t->right != nullptr)
                t = t->right;
        return t;
    }
    
    bool contains(const T& x, Node *t) const
    {
        if(t == nullptr)
            return false;

        else if(x < t->element)
            return contains(x, t->left);

        else if(t->element < x)
            return contains(x, t->right);
        
        else
            return true;
    }

    void makeEmpty(Node* &t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }


    void printTree(BST *t, ostream& out) const;
    BST* clone(BST *t) const;

};


int main() {

    BST<int> b1;

    b1.insert(10);
    b1.insert(5);
    b1.insert(15);
    b1.insert(2);
    b1.insert(7);
    b1.insert(12);

    cout << "Is the tree empty? " << (b1.isEmpty() ? "Yes" : "No") << endl;
    cout << "Minimum element: " << b1.findMin() << endl;
    cout << "Maximum element: " << b1.findMax() << endl;

    int elementToFind = 5;
    cout << "Does the tree contain " << elementToFind << "? " << (b1.contains(elementToFind) ? "Yes" : "No") << endl;

    cout << "Tree elements: ";
    // b1.printTree();

    b1.remove(5);
    cout << "After removing " << elementToFind << ": ";
    // b1.printTree();

    return 0;
}

