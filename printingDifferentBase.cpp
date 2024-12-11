#include <iostream>
using namespace std;

void printDifferentBase(int input){

    cout<<"Hexadecimal "<<" :"<<hex<<input<<endl;
    cout<<"Octal "<<" :"<<oct<<input<<endl;
}

int main(){
    int input;
    cout<<"Enter number :"<<endl;
    cin>>input;
    printDifferentBase(input);
}