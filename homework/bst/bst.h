#ifndef BSTREE_H
#define BSTREE_H

#include "iterator.h"
#include "stack.h"
#include "queue.h"
#include <cmath>

using namespace std;

template <typename T>
class BSTree
{
public:
    typedef BSTIterator<T> iterator;

private:
    NodeBT<T> *root;
    void inOrder(NodeBT<T> *node, string &result)
    {
        if (node != nullptr)
        {
            inOrder(node->left, result);
            result += to_string(node->data) + " ";
            inOrder(node->right, result);
        }
    }
    int balanceFactor(NodeBT<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = balanceFactor(node->left);
        if (leftHeight == -1)
        {
            return -1;
        }

        int rightHeight = balanceFactor(node->right);
        if (rightHeight == -1)
        {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
    NodeBT<T> *buildOrdered(T *array, int init, int end)
    {
        if (init > end)
        {
            return NULL;
        }

        int mid = (init + end) / 2;
        NodeBT<T> *nroot = new NodeBT<T>(array[mid]);
        nroot->left = buildOrdered(array, init, mid - 1);
        nroot->right = buildOrdered(array, mid + 1, end);

        return nroot;
    }
    void preOrder(NodeBT<T> *node, string &result)
    {
        if (node != nullptr)
        {
            result += to_string(node->data) + " ";
            preOrder(node->left, result);
            preOrder(node->right, result);
        }
    }
    void postOrder(NodeBT<T> *node, string &result)
    {
        if (node != nullptr)
        {
            postOrder(node->left, result);
            postOrder(node->right, result);
            result += to_string(node->data) + " ";
        }
    }

public:
    BSTree() : root(nullptr) {}

    void insert(T value) // implemented
    {
        if (root == nullptr)
        {
            root = new NodeBT<T>(value);
        }
        else
        {
            NodeBT<T> *temp = root;
            while (true)
            {
                if (value < temp->data)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = new NodeBT<T>(value);
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = new NodeBT<T>(value);
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    bool find(T value) // implemented
    {
        NodeBT<T> *temp = root;
        while (temp != nullptr)
        {
            if (value == temp->data)
            {
                return true;
            }
            else if (value < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    string displayInOrder() // implemented
    {
        string result = "";
        inOrder(root, result);
        return result;
    }
    string displayPreOrder() // implemented
    {
        string result = "";
        preOrder(root, result);
        return result;
    }
    string displayPostOrder() // implemented
    {
        string result = "";
        postOrder(root, result);
        return result;
    }
    int height() // implemented
    {
        if (root == nullptr)
        {
            return 0;
        }
        QueueArray<NodeBT<T> *> queue;
        queue.enqueue(root);
        int height = -1;
        while (!queue.is_empty())
        {
            int size = queue.size();
            height++;
            while (size > 0)
            {
                NodeBT<T> *temp = queue.dequeue();
                if (temp->left != nullptr)
                {
                    queue.enqueue(temp->left);
                }
                if (temp->right != nullptr)
                {
                    queue.enqueue(temp->right);
                }
                size--;
            }
        }
        return height;
    }
    T minValue() // implemented
    {
        NodeBT<T> *temp = root;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    T maxValue() // implemented
    {
        NodeBT<T> *temp = root;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->data;
    }
    void remove(T value) // implemented
    {
        NodeBT<T> *temp = root;
        NodeBT<T> *parent = nullptr;
        while (temp != nullptr && temp->data != value)
        {
            parent = temp;
            if (value < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (temp == nullptr)
        {
            throw runtime_error("Value not found");
        }
        if (temp->left == nullptr && temp->right == nullptr)
        {
            if (parent == nullptr)
            {
                root = nullptr;
            }
            else if (parent->left == temp)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
            delete temp;
        }
        else if (temp->left != nullptr && temp->right != nullptr)
        {
            NodeBT<T> *succesor = temp->right;
            NodeBT<T> *parentSuccesor = temp;
            while (succesor->left != nullptr)
            {
                parentSuccesor = succesor;
                succesor = succesor->left;
            }
            temp->data = succesor->data;
            if (parentSuccesor->left == succesor)
            {
                parentSuccesor->left = succesor->right;
            }
            else
            {
                parentSuccesor->right = succesor->right;
            }
            delete succesor;
        }
        else
        {
            NodeBT<T> *child = temp->left != nullptr ? temp->left : temp->right;
            if (parent == nullptr)
            {
                root = child;
            }
            else if (parent->left == temp)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
            delete temp;
        }
    }
    bool isBalanced() // implemented
    {
        return balanceFactor(root) != -1;
    }
    int size() // implemented
    {
        int size = 0;
        QueueArray<NodeBT<T> *> queue;

        if (root != nullptr)
        {
            queue.enqueue(root);
        }

        while (!queue.is_empty())
        {
            NodeBT<T> *temp = queue.dequeue();
            size++;

            if (temp->left != nullptr)
            {
                queue.enqueue(temp->left);
            }

            if (temp->right != nullptr)
            {
                queue.enqueue(temp->right);
            }
        }

        return size;
    }
    bool isFull()
    {
        return size() == pow(2, height() + 1) - 1;
    }
    T successor(T value) // implemented
    {
        NodeBT<T> *temp = root;
        NodeBT<T> *successor = nullptr;
        while (temp != nullptr)
        {
            if (value < temp->data)
            {
                successor = temp;
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return successor->data;
    }
    T predecessor(T value) // implemented
    {
        NodeBT<T> *temp = root;
        NodeBT<T> *predecessor = nullptr;
        while (temp != nullptr)
        {
            if (value > temp->data)
            {
                predecessor = temp;
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        return predecessor->data;
    }
    void clear() // implemented
    {
        while (root != nullptr)
        {
            remove(root->data);
        }
    }
    void buildFromOrderedArray(T *array, int n) // implemented
    {
        root = buildOrdered(array, 0, n - 1);
    };
    string displayBFS() // implemented
    {
        string result = "";
        QueueArray<NodeBT<T> *> queue;

        if (root != nullptr)
        {
            queue.enqueue(root);
        }

        while (!queue.is_empty())
        {
            NodeBT<T> *temp = queue.dequeue();
            result += to_string(temp->data) + " ";

            if (temp->left != nullptr)
            {
                queue.enqueue(temp->left);
            }

            if (temp->right != nullptr)
            {
                queue.enqueue(temp->right);
            }
        }

        return result;
    }
    string displayDFS() // implemented
    {
        string result = "";
        StackArray<NodeBT<T> *> stack;

        if (root != nullptr)
        {
            stack.push(root);
        }

        while (!stack.is_empty())
        {
            NodeBT<T> *temp = stack.pop();
            result += to_string(temp->data) + " ";

            if (temp->left != nullptr)
            {
                stack.push(temp->left);
            }

            if (temp->right != nullptr)
            {
                stack.push(temp->right);
            }
        }

        return result;
    }
    iterator begin(BSTIterator<int>::Type _)
    { // Retorna el inicio del iterador
        return BSTIterator<T>(root);
    };
    iterator end()
    {
        return BSTIterator<T>(nullptr);
    };        // Retorna el final del iterador
    ~BSTree() // implemented
    {
        clear();
    }
};

#endif
