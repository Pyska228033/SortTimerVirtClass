#ifndef doarr_H
#define doarr_H

#include "ArraySequence.h"
#include <chrono>
#include "sort.h"
#include <thread>

using namespace std;

template <class T>
void doarr(T* v, int n)
{
    auto begin6 = chrono::steady_clock::now();
    /*ARR*/
    ArraySequence<T> d = ArraySequence<T>(v, n);

   
    thread t1([&]()
        {
            auto begin = chrono::steady_clock::now();
            mergeSort<T>(&d, 0, d.GetLength() - 1);

            auto end = chrono::steady_clock::now();

            auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
            cout << "The time mergeSort: " << elapsed_ms.count() << " ms\n";
        });
  

    /*ARR next sort*/
    ArraySequence<T> d1 = ArraySequence<T>(v, n);

    
    thread t2([&]()
        {
            auto begin1 = chrono::steady_clock::now();
            selectionSort<T>(&d1);

            auto end1 = chrono::steady_clock::now();

            auto elapsed_ms1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
            cout << "The time selectionSort: " << elapsed_ms1.count() << " ms\n";
        });
    

    /*NEXTSORT*/
    ArraySequence<T> d2 = ArraySequence<T>(v, n);

   
    thread t3([&]()
        {
            auto begin2 = chrono::steady_clock::now();
            shellSort<T>(&d2);

            auto end2 = chrono::steady_clock::now();

            auto elapsed_ms2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
            cout << "The time shellSort: " << elapsed_ms2.count() << " ms\n";

        });
    
    t1.join();
    t2.join();
    t3.join();


    auto end6 = chrono::steady_clock::now();

    auto elapsed_ms6 = chrono::duration_cast<chrono::milliseconds>(end6 - begin6);
    cout << "The time: " << elapsed_ms6.count() << " ms\n";

    
    /*авто проверка*/
    int n1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (d.Get(i) <= d.Get(i + 1))
            n1++;
    }
    if ((n1 + 1) == n)
        cout << "mergeSort: Norm" << endl;
    else
        cout << "mergeSort: Hueta" << endl;


    int n2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (d1.Get(i) <= d1.Get(i + 1))
            n2++;
    }
    if ((n2 + 1) == n)
        cout << "selectionSort: Norm" << endl;
    else
        cout << "selectionSort: Hueta" << endl;


    int n3 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (d2.Get(i) <= d2.Get(i + 1))
            n3++;
    }
    if ((n3 + 1) == n)
        cout << "shellSort: Norm" << endl;
    else
        cout << "shellSort: Hueta" << endl;
}

#endif /*doarr_H*/
