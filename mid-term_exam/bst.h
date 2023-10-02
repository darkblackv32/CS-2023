#include <iostream>
#include <set>
using namespace std;

set<int> s1;

class BST {
public:
    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == nullptr)
            return nullptr;
        
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        
        return nullptr;
    }

    node* insert(int x, node* t)
    {
        if(t == nullptr)
        {
            t = new node;
            t->data = x;
            t->left = t->right = nullptr;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == nullptr)
            return nullptr;
        else if(t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == nullptr)
            return nullptr;
        else if(t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == nullptr)
            return nullptr;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == nullptr)
                t = t->right;
            else if(t->right == nullptr)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void in_order(node* t) {
        if(t == nullptr)
            return;
        in_order(t->left);
        cout << t->data << " ";
        in_order(t->right);
    }

    void pre_order(node* t) {
    if (t == nullptr)
        return;
    cout << t->data << " ";
    pre_order(t->left);
    pre_order(t->right);
    }

    void dfsPreorder(node* t) {
    if (t == nullptr)
        return;
    cout << t->data << " ";
    dfsPreorder(t->left);
    dfsPreorder(t->right);
    }




    node* find(node* t, int x) {
        if(t == nullptr)
            return nullptr;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }


public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void in_or_display() {
        in_order(root);
        cout << endl;
    }

    void pre_or_display() {
        pre_order(root);
        cout << endl;
    }

    void dfs_display() {
        dfsPreorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }

    void print_padre_dos(node* root) {
    
        if (root == nullptr) {
            return;  
        }
            
        if (root->left != nullptr && root->right != nullptr) {
            // cout << root->data << " "; 
            s1.emplace(root->data);

        }

        print_padre_dos(root->left);
        print_padre_dos(root->right);

    }




   

};


