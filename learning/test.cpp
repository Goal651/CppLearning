#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Create a jagged array with 3 rows
    int *jagged[3];
    
    // Allocate different column sizes for each row
    jagged[0] = new int[2]; // row 0 has 2 elements
    jagged[1] = new int[4]; // row 1 has 4 elements
    jagged[2] = new int[3]; // row 2 has 3 elements

    // Assign some values
    jagged[0][0] = 1;
    jagged[0][1] = 2;
    jagged[1][0] = 3;
    jagged[1][1] = 4;
    jagged[1][2] = 5;
    jagged[1][3] = 6;

    // Free memory
    for (int i = 0; i < 3; i++)
        delete[] jagged[i];
    return 0;
}