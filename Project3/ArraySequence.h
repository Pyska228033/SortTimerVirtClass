#ifndef ArraySequence_H
#define ArraySequence_H
#include "DynamicArray.h"
#include "Sequence.h"

using namespace std;

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* arr = new DynamicArray<T>;

public:

    ArraySequence(T* items, int count);
    ArraySequence(ArraySequence<T> d, ArraySequence<T> b);
    ArraySequence();
    T GetFirst() override;
    T GetLast() override;
    T Get(int index) override;
    int GetLength() override;
    void InsertAt(T item, int index) override;
    void Append(T item) override;
    void Prepend(T item) override;
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override;
    ArraySequence<T>* Concat(ArraySequence<T>* list);
    void print();
    T* Getad(int a) override;
    
};

template <class T>
ArraySequence<T> ::ArraySequence(T* items, int count)
{
    *arr = DynamicArray<T>(items, count);
}

template <class T>
ArraySequence<T> ::ArraySequence(ArraySequence<T> d, ArraySequence<T> b)
{
    *arr = DynamicArray<T>(*d.arr, *b.arr);
}

template <class T>
ArraySequence<T> ::ArraySequence()
{
    *arr = DynamicArray<T>();
}

template <class T>
T ArraySequence<T> ::GetFirst()
{
    T k = arr->Get(0);

    return k;
}

template <class T>
T ArraySequence<T> ::GetLast()
{
    int h = arr->GetSize();

    T k = arr->Get(h - 1);

    return k;
}

template <class T>
T ArraySequence<T> ::Get(int index)
{
    T k = arr->Get(index);

    return k;
}

template <class T>
T* ArraySequence<T> ::Getad(int a)
{
    T* b = arr->Getad(a);
    return b;
}

template <class T>
int ArraySequence<T> ::GetLength()
{
    int k = arr->GetSize();
    return k;
}

template <class T>
void ArraySequence<T> ::InsertAt(T item, int index)
{
    arr->Set(index, item);
}

template <class T>
void ArraySequence<T> ::Append(T item)
{
    int k = arr->GetSize();

    arr->Resize(k + 1);
    arr->Set(k, item);

}

template <class T>
void ArraySequence<T> ::Prepend(T item)
{

}

template <class T>
ArraySequence<T>* ArraySequence<T> ::GetSubsequence(int startIndex, int endIndex)
{
    ArraySequence<T>* frr = new ArraySequence<T>();

    return frr;
}

template <class T>
ArraySequence<T>* ArraySequence<T> ::Concat(ArraySequence<T>* list)
{
    ArraySequence<T>* frr = new ArraySequence<T>(*this, *list);

    return frr;

}

template <class T>
void ArraySequence<T> ::print()
{
    arr->print();
}





#endif /*ArraySequence_H*/