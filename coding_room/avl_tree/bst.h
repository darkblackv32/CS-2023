#include "node.h"

using namespace std;

template <typename T>
class AVLTree
{
private: 
    NodeBT<T> *root;

public:
    AVLTree() : root(nullptr) {}
    void insert(T value)
    {
        insert(this->root, value);
    }
   
    void displayPreOrder()
    {
        displayPreOrder(this->root);
    }

    int height()
    {
        return height(this->root);
    }

    void displayPretty()
    {
        displayPretty(this->root, 1);
    }
    
    ~AVLTree(){
        if(this->root != nullptr){
            this->root->killSelf();
        }
    }

private:
    void displayPreOrder(NodeBT<T> *node){
        if(node == nullptr) return;
        cout << node->data << ", ";
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }

    // void displayPretty(NodeBT<T> *node, int level)
    // {
    //     if (node == nullptr)
    //         return;
    //     displayPretty(node->right, level + 1);
    //     cout << endl;
    //     if (node == this->root)
    //         cout << "start->:  ";
    //     else
    //     {
    //         for (int i = 0; i < level; i++)
    //             cout << "      ";
    //     }
    //     cout << node->data ;
    //     displayPretty(node->left, level + 1);
    // }

    void displayPretty(NodeBT<T> *node, int level)
{
    // Base case: If the node is nullptr, return.
    if (node == nullptr)
        return;

    // Recursive call to display the right subtree with increased indentation level.
    displayPretty(node->right, level + 1);

    // Print a separator line between levels.
    if (level == 0)
        cout << "start->: ";
    else
    {
        for (int i = 0; i < level - 1; i++)
            cout << "      |"; // Add vertical bars to indicate tree structure.
        cout << "      +--";   // Add a horizontal branch for the current node.
    }

    // Print the node's data.
    cout << node->data << endl;

    // Recursive call to display the left subtree with increased indentation level.
    displayPretty(node->left, level + 1);
}



    /*add for avl*/
    void insert(NodeBT<T> *&node, T value){
        if(node == nullptr){
            node = new NodeBT<T>(value);
        }
        else if(value < node->data)
            insert(node->left, value);
        else 
            insert(node->right, value);

        if(node != nullptr){
            updateHeight(node);
            balance(node);
        }
    }


    int height(NodeBT<T> *node){//O(1)
        if(node == nullptr) return -1;
        return node->height;
    }

    void updateHeight(NodeBT<T> *node){//O(1)
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    int getHeight(NodeBT<T>* node) {
        if (node) return node->height;
        else return -1;
    }

    int balancingFactor(NodeBT<T> *node){

    }
  
    // void balance(NodeBT<T> *&node){
    //     int hb = balancingFactor(node);
    //     if(hb >= 2 ){//inclinado a la izquierda
    //         if(balancingFactor(node->left) <= -1)
    //             left_rota(node->left);
    //         right_rota(node);
    //     }
    //     else if(hb <= -2){//inclinado a la derecha
    //         if(balancingFactor(node->right) >= 1)
    //             right_rota(node->right);
    //         left_rota(node);
    //     }
    // }

    void balance(NodeBT<T>*& node) {
        int balanceFactor = getHeight(node->left) - getHeight(node->right);

        if (balanceFactor > 1) {
            if (getHeight(node->left->left) >= getHeight(node->left->right)) {
                right_rota(node);
            }
            else {
                left_rota(node->left);
                right_rota(node);
            }
        }
        else if (balanceFactor < -1) {
            if (getHeight(node->right->right) >= getHeight(node->right->left)) {
                left_rota(node);
            }
            else {
                right_rota(node->right);
                left_rota(node);
            }
        }
    }

    void left_rota(NodeBT<T>*& node) {
        NodeBT<T>* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        node = newRoot;

        updateHeight(node->left);
        updateHeight(node);
    }


    void right_rota(NodeBT<T>*& node) {
        NodeBT<T>* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        node = newRoot;

        updateHeight(node->right);
        updateHeight(node);
    }

};