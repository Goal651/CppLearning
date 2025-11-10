#include <iostream>
using namespace std;

int main() {
    int abc = 10;
    double def = 10.6;
    char ghi = 'c';
    int test = *&abc;
    int *p = &abc;

    cout << "The address of abc is " << &abc << endl;
    cout << "The address of def is " << &def << endl;
    cout << "The address of ghi is " << &ghi << endl;
    cout << "Testing " << *p << endl;


    return 0;
}