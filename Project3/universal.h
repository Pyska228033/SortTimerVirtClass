#ifndef UNIVERSAL_H
#define UNIVERSAL_H

#include <string>
#include "doarr.h"
#include "dolist.h"

using namespace std;

template <class T>
void universal()

    {
        cout << "SORT COMPARISON ALGORITHM" << endl;
        cout << "Type <do> to start" << endl;

        string p;
        cin >> p;

        while (p == "do")
        {
            cout << "Manual input or autocomplate?" << endl;
            string e;
            cin >> e;

            int n;
            cout << "Enter the number of items to sort:";
            cin >> n;
            T* v = new T[n];
            srand(time(0));

            if (e == "manual")
            {
                for (int i = 0; i < n; i++)
                {
                    T newc;
                    cin >> newc;
                    v[i] = newc;
                }
            }

            else if (e == "auto")
            {
                for (int i = 0; i < n; i++)
                    v[i] = rand();
            }

            else
            {
                cout << "error";
                assert(0);
            }
            cout << "I want to see the results for..." << endl;

            string s;
            cin >> s;

            string s1;

            while (s1 != "no")
            {
                if (s == "arr" || s1 == "yes")
                {
                    doarr<T>(v, n);

                    cout << "want to list?" << endl;
                    cin >> s1;
                }

                if (s == "list" || s1 == "yes")
                {
                    dolist<T>(v, n);

                    s = "\0";

                    cout << "want to arr?" << endl;
                    cin >> s1;
                }
            }

            cout << endl;
            cout << "Type <do> to start" << endl;
            cout << "Type <end> to stop" << endl;
            cin >> p;
        }
        system("pause");
    }


#endif // !UNIVERSAL_H

