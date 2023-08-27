#ifndef Sequence_H
#define Sequence_H
#include <iostream>

using namespace std;

template <class T>
class Sequence
{

public:
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual T* Getad(int a) = 0;
};

#endif /*Sequence_H*/
