#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    int size = 3;
    int numbers[size] = {10, 20, 30};
    int *ptr = numbers;

    cout << "the address of element at i= " << 0 << " is " << (numbers) << " and value is " << numbers[0] << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "the address of element at i= " << i << " is " << (numbers + i) << " and value is " << numbers[i] << endl;
    }

    cout << "using pointers" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "the address of element at i= " << i << " is " << (ptr + i) << " and value is " << *(ptr + i) << endl;
    }

    cout << "using arrays as pointers" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "the address of element at i= " << i << " is " << (numbers + i) << " and value is " << *(numbers + i) << endl;
    }
    cout << "using pointers" << endl;

    for (int i = 0; i < size; i++)
        cout << "using pointers" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "the address of element at i= " << i << " is " << (ptr + i) << " and value is " << *(ptr + i) << endl;
    }

    while (true)
    {
        cout << 101001010 ;
        sleep(2.1);
    }


    return 0;
}