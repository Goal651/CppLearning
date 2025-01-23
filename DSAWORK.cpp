#include <iostream>
#include <string>
#include <limits>
#include <algorithm> // For transform function

using namespace std;

struct CustomerLinkedList
{
    int code;
    string name;
    string dob;
    int balance;
    CustomerLinkedList *next;

    CustomerLinkedList() : next(nullptr) {}
    CustomerLinkedList(int c, string n, string d, int b) : code(c), name(n), dob(d), balance(b), next(nullptr) {}
};

struct TransactionLinkedList
{
    int id;
    string type;
    int customer_code;
    int amount;
    string date;
    TransactionLinkedList *next;

    TransactionLinkedList() : next(nullptr) {}
    TransactionLinkedList(int i, string t, int cc, int a, string d) : id(i), type(t), customer_code(cc), amount(a), date(d), next(nullptr) {}
};

class BankSystem
{
private:
    CustomerLinkedList *customerHead = nullptr;
    TransactionLinkedList *transactionHead = nullptr;

    void addCustomer()
    {
        int code, balance;
        string name, dob;

        cout << "Enter customer code: ";
        while (!(cin >> code))
        {
            cout << "Invalid input. Please enter a valid integer for code: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(); // To clear the input buffer
        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter customer date of birth: ";
        getline(cin, dob);

        cout << "Enter customer balance: ";
        while (!(cin >> balance))
        {
            cout << "Invalid input. Please enter a valid integer for balance: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        CustomerLinkedList *newCustomer = new CustomerLinkedList(code, name, dob, balance);
        newCustomer->next = customerHead;
        customerHead = newCustomer;

        cout << "Customer added successfully.\n";
    }

    void addTransaction()
    {
        int id, customer_code, amount;
        string type, date;

        cout << "Enter transaction ID: ";
        while (!(cin >> id))
        {
            cout << "Invalid input. Please enter a valid integer for ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Repeated prompt until a valid type is entered
        while (true)
        {
            cout << "Enter transaction type (Deposit/Withdrawal): ";
            cin.ignore();
            getline(cin, type);
            // Convert the type to lowercase to make it case-insensitive
            transform(type.begin(), type.end(), type.begin(), ::tolower);

            if (type == "deposit" || type == "withdrawal")
            {
                break; // Exit loop if valid input
            }
            else
            {
                cout << "Invalid input. Please enter either 'Deposit' or 'Withdrawal'." << endl;
            }
        }

        cout << "Enter customer code: ";
        while (!(cin >> customer_code))
        {
            cout << "Invalid input. Please enter a valid integer for customer code: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter transaction amount: ";
        while (!(cin >> amount))
        {
            cout << "Invalid input. Please enter a valid integer for amount: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter transaction date (YYYY-MM-DD): ";
        cin.ignore();
        getline(cin, date);

        TransactionLinkedList *newTransaction = new TransactionLinkedList(id, type, customer_code, amount, date);
        newTransaction->next = transactionHead;
        transactionHead = newTransaction;

        // Update customer's balance based on transaction type
        CustomerLinkedList *customer = findCustomerByCode(customer_code);
        if (customer != nullptr)
        {
            if (type == "deposit")
            {
                customer->balance += amount;
                cout << "Deposit successful. Updated balance: " << customer->balance << "\n";
            }
            else if (type == "withdrawal")
            {
                if (customer->balance >= amount)
                {
                    customer->balance -= amount;
                    cout << "Withdrawal successful. Updated balance: " << customer->balance << "\n";
                }
                else
                {
                    cout << "Insufficient balance for withdrawal.\n";
                }
            }
        }
        else
        {
            cout << "Customer with code " << customer_code << " not found.\n";
        }

        cout << "Transaction added successfully.\n";
    }

    CustomerLinkedList *findCustomerByCode(int code)
    {
        CustomerLinkedList *current = customerHead;
        while (current != nullptr)
        {
            if (current->code == code)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Customer not found
    }

    void displayCustomers()
    {
        if (!customerHead)
        {
            cout << "No customers to display.\n";
            return;
        }

        CustomerLinkedList *current = customerHead;
        while (current != nullptr)
        {
            cout << "Code: " << current->code << ", Name: " << current->name
                 << ", DOB: " << current->dob << ", Balance: " << current->balance << "\n";
            current = current->next;
        }
    }

    void displayTransactions()
    {
        if (!transactionHead)
        {
            cout << "No transactions to display.\n";
            return;
        }

        TransactionLinkedList *current = transactionHead;
        while (current != nullptr)
        {
            cout << "ID: " << current->id << ", Type: " << current->type
                 << ", Customer Code: " << current->customer_code << ", Amount: " << current->amount
                 << ", Date: " << current->date << "\n";
            current = current->next;
        }
    }

public:
    void displayMenu()
    {
        int choice;

        do
        {
            cout << "\nBank System Menu\n";
            cout << "1. Add Customer\n";
            cout << "2. Add Transaction\n";
            cout << "3. Display Customers\n";
            cout << "4. Display Transactions\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            while (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a valid choice: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (choice)
            {
            case 1:
                addCustomer();
                break;
            case 2:
                addTransaction();
                break;
            case 3:
                displayCustomers();
                break;
            case 4:
                displayTransactions();
                break;
            case 5:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
        } while (choice != 5);
    }
};

int main()
{
    BankSystem bankSystem;
    bankSystem.displayMenu();
    return 0;
}
