#include <iomanip>
#include <iostream>
using namespace std;

void formatInputs(string names, string age, string address) {
    cout << setw(10) << "Name" << "\tAge\tAddress\n\v";
    cout << setw(10) << names << "\t" << age << "\t" << address << "\t" << endl;
}

int main() {
    string names, age, address;
    cout << "Enter names: \n";
    getline(cin, names);
    cout << "Enter age: " << endl;
    cin >> age;
    cout << "Enter address: " << endl;
    cin >> address;
    formatInputs(names, age, address);
    return 0;
}