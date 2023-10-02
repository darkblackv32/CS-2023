#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack> // for stack-based traversals
#include <queue> // for BFS traversal

template <typename T>
class BSTIterator
{
public:
    enum Type {
        PreOrder, InOrder, PostOrder, BFS
    };

private:
    NodeBT<T> *current;
    Type type;
    std::stack<NodeBT<T>*> stack; // For stack-based traversals
    std::queue<NodeBT<T>*> queue; // For BFS traversal

    void initializeTraversal() {
        if (type == PreOrder || type == PostOrder) {

            stack.push(current);
        }
        if (type == BFS) {

            if (current) {
                queue.push(current);
            }
        } else {

            while (current) {
                stack.push(current);
                current = (type == PreOrder) ? current->left : current->right;
            }
        }
    }

public:
    BSTIterator() : current(nullptr), type(InOrder) {}
    BSTIterator(NodeBT<T> *root, Type t = InOrder) : current(root), type(t) {
        initializeTraversal();
    }

    BSTIterator<T> &operator=(const BSTIterator<T> &other) {
        if (this != &other) {
            current = other.current;
            type = other.type;
            stack = other.stack;
            queue = other.queue;
        }
        return *this;
    }

    bool operator!=(const BSTIterator<T> &other) {
        return current != other.current;
    }

    BSTIterator<T> &operator++() {
        if (type == BFS) {
            if (!queue.empty()) {
                current = queue.front();
                queue.pop();

                if (current) {
                    if (current->left) {
                        queue.push(current->left);
                    }
                    if (current->right) {
                        queue.push(current->right);
                    }
                }
            } else {
                current = nullptr; 
            }
        } else {
            if (!stack.empty()) {
                current = stack.top();
                stack.pop();

                NodeBT<T> *temp = (type == InOrder) ? current->right : current->left;
                while (temp) {
                    stack.push(temp);
                    temp = (type == InOrder) ? temp->left : temp->right;
                }
            } else {
                current = nullptr;
            }
        }

        return *this;
    }

    T operator*() {
        if (current) {
            return current->data;
        }
        return T(); 
    }
};

#endif


