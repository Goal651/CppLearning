#include <iostream>
#define PI 3.14
using namespace std;

float findCircleArea(float radius)
{
    float area = PI * radius * radius;
    return area;
}

int main()
{
    float radius;
    cout << "Enter radius :" << endl;
    cin >> radius;
    float area = findCircleArea(radius);
    cout << "Area of circle is :" << area << endl;
    return 0;
}