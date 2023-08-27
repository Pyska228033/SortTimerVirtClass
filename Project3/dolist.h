#ifndef dolist_H
#define dolist_H

#include "LinkedListSequence.h"
#include <chrono>
#include "sort.h"
#include <thread>

using namespace std;

template <class T>
void dolist(T* v, int n)
{
    auto begin6 = chrono::steady_clock::now();
    /*List*/
    LinkedListSequence<T> k1 = LinkedListSequence<T>(v, n);
    thread t1([&]()
        {
            auto begin3 = chrono::steady_clock::now();

            shellSort<T>(&k1);

            auto end3 = chrono::steady_clock::now();

            auto elapsed_ms3 = chrono::duration_cast<chrono::milliseconds>(end3 - begin3);
            cout << "The time shellSort List: " << elapsed_ms3.count() << " ms\n";
        });
    /*NEXTSORT*/
    LinkedListSequence<T> k2 = LinkedListSequence<T>(v, n);
    thread t2([&]()
        {
            auto begin4 = chrono::steady_clock::now();

            mergeSort<T>(&k2, 0, k2.GetLength() - 1);

            auto end4 = chrono::steady_clock::now();

            auto elapsed_ms4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
            cout << "The time mergeSort List: " << elapsed_ms4.count() << " ms\n";
        });

    /*NEXTSORT*/
    LinkedListSequence<T> k3 = LinkedListSequence<T>(v, n);

    thread t3([&]()
        {
            auto begin5 = chrono::steady_clock::now();

            selectionSort<T>(&k3);

            auto end5 = chrono::steady_clock::now();

            auto elapsed_ms5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
            cout << "The time selectionSort List: " << elapsed_ms5.count() << " ms\n";
        });

    t1.join();
    t2.join();
    t3.join();

    auto end6 = chrono::steady_clock::now();

    auto elapsed_ms6 = chrono::duration_cast<chrono::milliseconds>(end6 - begin6);
    cout << "The time: " << elapsed_ms6.count() << " ms\n";

    cout << "source list:" << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl << endl;

    cout << "shellSort List:" << endl;
    k1.print();
    cout << endl;

    cout << "mergeSort List:" << endl;
    k2.print();
    cout << endl;

    cout << "selectionSort List:" << endl;
    k3.print();
    cout << endl;


    /*авто проверка*/
    int n4 = 0;
    for (int i = 0; i < n; i++)
    {
        if (k1.Get(i) <= k1.Get(i))
            n4++;
    }
    if (n4 == n)
        cout << "shellSort List: Norm" << endl;
    else
        cout << "shellSort List: Hueta" << endl;


    int n5 = 0;
    for (int i = 0; i < n; i++)
    {
        if (k2.Get(i) <= k2.Get(i))
            n5++;
    }
    if (n5 == n)
        cout << "mergeSort List: Norm" << endl;
    else
        cout << "mergeSort List: Hueta" << endl;


    int n6 = 0;
    for (int i = 0; i < n; i++)
    {
        if (k3.Get(i) <= k3.Get(i))
            n6++;
    }
    if (n6 == n)
        cout << "selectionSort List: Norm" << endl;
    else
        cout << "selectionSort List: Hueta" << endl;
}



#endif /*dolist_H*/