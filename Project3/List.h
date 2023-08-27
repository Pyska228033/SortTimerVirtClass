#ifndef List_H
#define List_H
#include <iostream>
#include "Nudl.h"
#include <assert.h>

using namespace std;

template <class T>
class List
{
private:
    Nudl<T>* ne1 = new Nudl<T>;

public:

    List();
    List(T* arr, int n);
    List(List<T> d, List<T> b);
    int GetLength();
    T GetFirst();
    T GetLast();
    T Get(int n);
    List<T>* GetSubList(int str, int end);
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int n);
    List<T>* Concat(List<T>* b);
    void printList();
    T* Getad(int a);
   
};

template <class T>
List<T> ::List()
{
    
}

template <class T>
List<T> ::List(T* arr, int n)
{
    Nudl<T>* ne = new Nudl<T>;

    ne->data = *arr;
    ne->next = NULL;
    ne1 = ne;

    for (int i = 1; i < n; i++)
    {

        Nudl<T>* ne2 = new Nudl<T>;
        ne2->data = *(arr + i);
        ne2->next = NULL;

        while (ne->next != NULL)
        {
            ne = ne->next;
        }
        ne->next = ne2;
    }

}

template <class T>
List<T> ::List(List<T> d, List<T> b)
{
    Nudl<T>* ne2 = new Nudl<T>;

    ne2 = d.ne1;
    ne1 = ne2;

    while (ne2->next != NULL)
    {
        ne2 = ne2->next;
    }

    ne2->next = b.ne1;

}

template <class T>
int List<T> ::GetLength()
{
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;

    int n = 0;

    while (ne != NULL)
    {
        n++;
        ne = ne->next;
    }

    return n;
}

template <class T>
T List<T> ::GetFirst()
{
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;
    int n = 0;

    while (ne != NULL)
    {
        ne = ne->next;
        n++;
    }

    if ((n == 1 && (ne->data) == 1357))
        assert(0);

    T k;

    k = (ne1->data);

    return k;
}

template <class T>
T List<T> ::GetLast()
{
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;
    int n = 0;

    while (ne != NULL)
    {
        ne = ne->next;
        n++;
    }

    if ((n == 1 && (ne->data) == 1357))
        assert(0);

    T k;

    while (ne1->next != NULL)
    {
        ne1 = ne1->next;
    }

    k = ne1->data;

    return k;
}

template <class T>
T List<T> ::Get(int n)
{
    
    T k;

    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;

    for (int i = 0; i < n; i++)
    {
        ne = ne->next;
    }

    k = ne->data;

    return k;
}

template <class T>
List<T>* List<T> ::GetSubList(int str, int end)
{
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;
    int n = 0;

    while (ne != NULL)
    {
        ne = ne->next;
        n++;
    }

    if ((n == 1 && (ne->data) == 1357) || str < 0 || end < 0 || end < str)
        assert(0);

    List<T>* d = new List<T>();

    for (int i = 0; i < str; i++)
    {
        ne1 = ne1->next;
    }

    (d->ne1) = ne1;

    for (int i = 0; i < (end - str); i++)
    {
        ne1 = ne1->next;
    }
    ne1->next = NULL;

    return d;

}

template <class T>
void List<T> ::Append(T item)
{
    Nudl<T>* ne = new Nudl<T>;
    Nudl<T>* ne2 = new Nudl<T>;

    ne = ne1;

    ne2->data = item;
    ne2->next = NULL;

    while (ne->next != NULL)
    {
        ne = ne->next;
    }

    ne->next = ne2;
}

template <class T>
void List<T> ::Prepend(T item)
{
    Nudl<T>* ne2 = new Nudl<T>;

    ne2->data = item;
    ne2->next = ne1;

    ne1 = ne2;
}

template <class T>
void List<T> ::InsertAt(T item, int n)
{
   
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;

    for (int i = 0; i < n; i++)
    {
        ne = ne->next;
    }

    ne->data = item;
}

template <class T>
List<T>* List<T> ::Concat(List<T>* b)
{
    List<T>* a = new List<T>();
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;
    Nudl<T>* ne3 = new Nudl<T>;
    ne3->data = ne->data;
    ne3->next = NULL;
    a->ne1 = ne3;
    ne = ne->next;

    while (ne != NULL)
    {
        Nudl<T>* ne4 = new Nudl<T>;
        ne4->data = ne->data;
        ne3->next = ne4;
        ne3 = ne3->next;
        ne = ne->next;
    }

    Nudl<T>* ne2 = new Nudl<T>;
    ne2 = b->ne1;

    while (ne2 != NULL)
    {
        Nudl<T>* ne4 = new Nudl<T>;
        ne4->data = ne2->data;
        ne4->next = NULL;
        ne3->next = ne4;
        ne3 = ne3->next;
        ne2 = ne2->next;
    }

    return a;


}

template <class T>
void List<T> ::printList()
{
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;

    while (ne != NULL)
    {
        cout << ne->data << " ";
        ne = ne->next;
    }
    cout << endl;
}

template <class T>
T* List<T> ::Getad(int a)
{
    Nudl<T>* ne = new Nudl<T>;
    ne = ne1;

    for (int i = 0; i < a; i++)
    {
        ne = ne->next;
    }

    T* b = &(ne->data);
    return b;
}





#endif /*List_H*/
