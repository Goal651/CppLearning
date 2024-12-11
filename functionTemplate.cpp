#include <iostream>
using namespace std;

template <typename T>
void print(T n)
{
    cout << "Octal: " << oct << n << endl;
    cout << "Hexadecimal: " << hex << n << endl;
    cout << "Decimal: " << dec << n << endl;
}


int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    print<int>(n);
    return 0;
}