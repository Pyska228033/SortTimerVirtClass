#ifndef SORT_H
#define SORT_H

#include "Sequence.h"
#include <thread>

using namespace std;

template <class T>
void swap(T* a, T* b)
{
    T k = *a;
    *a = *b;
    *b = k;
}

template <class T>
int findSmallestPosition(Sequence<T>* a, int startPosition, int listLength)
{
    int smallestPosition = startPosition;

    for (int i = startPosition; i < listLength; i++)
    {
        if (a -> Get(i) < a -> Get(smallestPosition))
        smallestPosition = i;
    }
    return smallestPosition;
}

template <class T>
void selectionSort(Sequence<T>* a)
{
    for (int i = 0; i < a -> GetLength(); i++)
    {
        int smallestPosition = findSmallestPosition(a, i, a -> GetLength());


        swap((a -> Getad(i)), (a -> Getad(smallestPosition)));
    }
}

template <class T>
void merge(Sequence<T>* a, int start, int end, int mid)
{
    int n = a -> GetLength();
    T* mergedList = new T[n];
    int i, j, k;
    i = start;
    k = start;
    j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (a -> Get(i) < a -> Get(j))
        {
            mergedList[k] = a -> Get(i);
            k++;
            i++;
        }
        else
        {
            mergedList[k] = a -> Get(j);
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        mergedList[k] = a -> Get(i);
        k++;
        i++;
    }

    while (j <= end)
    {
        mergedList[k] = a -> Get(j);
        k++;
        j++;
    }

    for (i = start; i < k; i++)
    {
        a -> InsertAt(mergedList[i], i);
    }
}

template <class T>
void mergeSort(Sequence<T>* a, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, end, mid);
    }
}

template <class T>
void shellSort(Sequence<T>* a)
{
    int n = a -> GetLength();
    int d = n;
    d = d / 2;

    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && a ->Get(j) > a -> Get(j + d))
            {
                T count = a -> Get(j);
                a -> InsertAt(a -> Get(j + d),j) ;
                a -> InsertAt(count, j + d);
                j--;
            }
        }
        d = d / 2;
    }
}


#endif // !SORT_H

