#include <iostream>
#include <cmath>
using namespace std;

double calculateHypotenuse(int a, int b)
{
    double hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
    return hypotenuse;
}

void findRoots(int a, int b, int c)
{
    double numerator1 = -b + sqrt(pow(b, 2) - (4 * a * c));
    double numerator2 = -b - sqrt(pow(b, 2) - (4 * a * c));
    double denominator = 2 * a;
    double root1 = numerator1 / denominator;
    double root2 = numerator2 / denominator;

    cout << "root1 is " << root1 << endl;
    cout << "root2 is " << root2 << endl;
}

int main()
{
    int a, b, c;
    cout << "Enter a,b and c:\n";
    cin >> a >> b >> c;
    findRoots(a, b, c);
    return 0;
}