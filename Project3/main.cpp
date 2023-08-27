#include "universal.h"

using namespace std;

int main()
{
    cout << "1. int" << endl << "2. duble" << endl << "3. float" << endl;

    char l;
    cin >> l;

    if(l == '1')
    universal<int>();
    if(l == '2')
    universal<double>();
    if (l == '3')
    universal<float>();

    return 0;
}