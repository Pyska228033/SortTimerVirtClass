#ifndef LinkedListSequence_H
#define LinkedListSequence_H
#include "List.h"
#include "Sequence.h"

using namespace std;

template <class T>
class LinkedListSequence : public Sequence<T>
{
private:
    List<T>* arr = new List<T>;

public:

    LinkedListSequence(T* items, int count);
    LinkedListSequence();
    LinkedListSequence(LinkedListSequence <T> d, LinkedListSequence<T> b);
    T GetFirst() override;
    T GetLast() override;
    T Get(int index) override;
    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) override;
    int GetLength() override;
    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override;
    LinkedListSequence<T>* Concat(LinkedListSequence<T>* list);
    void print();
    T* Getad(int a) override;

};

template <class T>
LinkedListSequence <T> ::LinkedListSequence(T* items, int count)
{
    *arr = List<T>(items, count);
}

template <class T>
LinkedListSequence <T> ::LinkedListSequence()
{
    *arr = List<T>();
}

template <class T>
LinkedListSequence <T> ::LinkedListSequence(LinkedListSequence <T> d, LinkedListSequence<T> b)
{
    *arr = List<T>(*d.arr, *b.arr);
}

template <class T>
T LinkedListSequence <T> ::GetFirst()
{
    T k = arr->GetFirst();
    return k;
}

template <class T>
T LinkedListSequence <T> ::GetLast()
{
    T k = arr->GetLast();
    return k;
}

template <class T>
T LinkedListSequence <T> ::Get(int index)
{
    T k = arr->Get(index);
    return k;
}

template <class T>
LinkedListSequence<T>* LinkedListSequence <T> ::GetSubsequence(int startIndex, int endIndex)
{
    LinkedListSequence<T>* a = new LinkedListSequence<T>();

    a->arr = arr->GetSubList(startIndex, endIndex);
    return a;
}

template <class T>
int LinkedListSequence <T> ::GetLength()
{
    int k = arr->GetLength();
    return k;
}

template <class T>
void LinkedListSequence <T> ::Append(T item)
{
    arr->Append(item);
}

template <class T>
void LinkedListSequence <T> ::Prepend(T item)
{
    arr->Prepend(item);
}

template <class T>
void LinkedListSequence <T> ::InsertAt(T item, int index)
{
    arr->InsertAt(item, index);
}

template <class T>
LinkedListSequence<T>* LinkedListSequence <T> ::Concat(LinkedListSequence<T>* list)
{
    LinkedListSequence<T>* a = new LinkedListSequence<T>;
    a->arr = arr->Concat(list->arr);
    return a;
}

template <class T>
void LinkedListSequence <T> ::print()
{
    arr->printList();
}

template <class T>
T* LinkedListSequence <T> ::Getad(int a)
{
    T* b = arr->Getad(a);
    return b;
}




#endif /*LinkedListSequence*/
