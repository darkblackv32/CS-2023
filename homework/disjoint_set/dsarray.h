#ifndef DSARRAY_H
#define DSARRAY_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class DisjoinSetArray
{
private:
    T *data;
    int *parent;
    int *rank;

public:
    // implement all functions
    DisjoinSetArray(vector<T> data)
    {
        this->data = new T[data.size()];
        this->parent = new int[data.size()];
        this->rank = new int[data.size()];
        for (int i = 0; i < data.size(); i++)
        {
            this->data[i] = data[i];
            parent[i] = i;
            rank[i] = 0;
        }
    }
    ~DisjoinSetArray()
    {
        delete[] data;
        delete[] parent;
        delete[] rank;
    }

    void print()
    {
        int size_d = sizeof(data) / sizeof(data[0]);

        cout << "Data:   ";

        for (int i = 0; i < size_d; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
        cout << "Parent: ";
        for (int i = 0; i < size_d; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
        cout << "Rank:   ";
        for (int i = 0; i < size_d; i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
        cout << endl;
    }

    /*
     * x, y are indexes
     */
    // MakseSet the element with index x
    void MakeSet(int x)
    {
        parent[x] = x;
        rank[x] = 0;
    }
    // Find the root of x (with optimization by rank)
    int Find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = Find(parent[x]);
    }
    // Find the root of x (with optimization path compression)
    int FindPathCompression(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = FindPathCompression(parent[x]);
    }
    // Union two sets represented by x and y (apply rank)
    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);
        if (xRoot != yRoot)
        {
            if (rank[xRoot] > rank[yRoot])
            {
                parent[yRoot] = xRoot;
            }
            else
            {
                parent[xRoot] = yRoot;
            }
            if (rank[xRoot] == rank[yRoot])
            {
                rank[yRoot]++;
            }
        }
    }

    // check whether there is a path between x and y
    bool isConnected(int x, int y)
    {
        return Find(x) == Find(y);
    }
    // total number of elements
    int size()
    {
        return sizeof(data) / sizeof(data[0]);
    }
    // number of sets
    int sets()
    {
        int count = 0;
        for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        {
            if (parent[i] == i)
            {
                count++;
            }
        }
        return count;
    }
    // total number of elements that belong to the set of x
    int size(int x) // Complejidad: O(n)
    {
        int count = 0;
        x = Find(x);
        for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        {
            if (parent[i] == x)
            {
                count++;
            }
        }
        return count;
    }
    // add the element to the set of x
    void add(T element, int x)
    {
        int size_d = sizeof(data) / sizeof(data[0]);
        T *new_data = new T[size_d + 1];
        int *new_parent = new int[size_d + 1];
        int *new_rank = new int[size_d + 1];
        for (int i = 0; i < size_d; i++)
        {
            new_data[i] = data[i];
            new_parent[i] = parent[i];
            new_rank[i] = rank[i];
        }
        new_data[size_d] = element;
        new_parent[size_d] = x;
        new_rank[size_d] = 0;
        delete[] data;
        delete[] parent;
        delete[] rank;
        data = new_data;
        parent = new_parent;
        rank = new_rank;
    }
    // return all elements that belong to the set of x
    vector<T> getElementsSet(int x) // Complejidad: O(n)
    {
        vector<T> elements;
        for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        {
            if (parent[i] == x)
            {
                elements.push_back(data[i]);
            }
        }
        return elements;
    }
};

#endif