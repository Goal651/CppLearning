#include <iostream>
using namespace std;
int main()
{
    int i = 20;
    cout << &i << endl;
    int *p = &i;
    cout << p << endl;
    cout << *p << endl;

    char c = 'c';
    char *p2 = &c;
    cout << p2 << endl;
    cout << &p2 << endl;

    return 0;
}