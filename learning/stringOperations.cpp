#include <iostream>
#include <cstring>

using namespace std;

void calculateStringLength(char b[])
{
    int length = 0;
    while (b[length] != '\0')
    {
        cout<<b[length]<<endl;
        length++;
    }
    cout<<length<<endl;
}

int main()
{
    char str[80];
    strcpy(str, "Hello");
    strcat(str, " World");
    cout << str << endl;
    calculateStringLength(str);
    return 0;
}