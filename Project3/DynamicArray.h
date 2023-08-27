#ifndef DynamicArray_H
#define DynamicArray_H
#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class DynamicArray
{
private:
    int n;
    T* x = new T[1000000];
   

public:

    DynamicArray();
    DynamicArray(T* items, int count);
    DynamicArray(int size);
    DynamicArray(DynamicArray<T> d, DynamicArray<T> b);
    T Get(int index);
    int GetSize();
    void Set(int index, T value);
    void Resize(int newSize);
    void print();
    T* Getad(int a);

};

template <class T>
DynamicArray<T> ::DynamicArray()
{
    n = 0;
    x = NULL;
}

template <class T>
DynamicArray<T> ::DynamicArray(T* items, int count)
{
    n = count;

    for (int i = 0; i < count; i++)
    {
        x[i] = items[i];
    }
}

template <class T>
DynamicArray<T> ::DynamicArray(int size)
{
    n = size;

    for (int i = 0; i < size; i++)
    {
        x[i] = 0;
    }
}

template <class T>
DynamicArray<T> ::DynamicArray(DynamicArray<T> d, DynamicArray<T> b)
{
    n = d.n + b.n;
    int h = d.n;

    for (int i = 0; i < d.n; i++)
    {
        x[i] = d.x[i];
    }

    for (int i = 0; i < b.n; i++)
    {
        x[h] = b.x[i];
        h++;
    }
}

template <class T>
T DynamicArray<T> ::Get(int index)
{
    return x[index];
}

template <class T>
T* DynamicArray<T> ::Getad(int index)
{
    return &x[index];
}

template <class T>
int DynamicArray<T> ::GetSize()
{
    return n;
}

template <class T>
void DynamicArray<T> ::Set(int index, T value)
{
    

    x[index] = value;
}

template <class T>
void DynamicArray<T> ::Resize(int newSize)
{
    n = newSize;
}

template <class T>
void DynamicArray<T> ::print()
{

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << ' ';
    }
    cout << endl;
}





#endif /*DynamicArray_H*/
