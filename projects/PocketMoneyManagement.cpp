#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <regex>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

struct CustomerLinkedList {
    int code;
    string name;
    string dob;
    int balance;
    CustomerLinkedList *next;

    CustomerLinkedList() : next(nullptr) {}
    CustomerLinkedList(int c, string n, string d, int b) : code(c), name(n), dob(d), balance(b), next(nullptr) {}
};

struct TransactionLinkedList {
    int id;
    string type;
    int customer_code;
    int amount;
    string date;
    TransactionLinkedList *next;

    TransactionLinkedList() : next(nullptr) {}
    TransactionLinkedList(int i, string t, int cc, int a, string d) : id(i), type(t), customer_code(cc), amount(a), date(d), next(nullptr) {}
};

class BankSystem {
  private:
    CustomerLinkedList *customerHead = nullptr;
    TransactionLinkedList *transactionHead = nullptr;

    // Static variable to auto-increment transaction ID
    static int transactionIDCounter;

    // Function to validate date format (DD/MM/YYYY)
    bool isValidDate(const string &date) {
        regex datePattern("\\d{2}/\\d{2}/\\d{4}"); // Regex for DD/MM/YYYY format
        return regex_match(date, datePattern);
    }

    void addCustomer() {
        int code, balance;
        string name, dob;

        cout << "Enter customer code: ";
        while(!(cin >> code)) {
            cout << "Invalid input. Please enter a valid integer for code: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Check if the code already exists
        if(findCustomerByCode(code) != nullptr) {
            cout << "Error: Customer code already exists. Please enter a unique code.\n";
            return; // Exit the method without adding the customer
        }

        cin.ignore(); // To clear the input buffer
        cout << "Enter customer name: ";
        getline(cin, name);

        // Validate the date format
        cout << "Enter customer date of birth (DD/MM/YYYY): ";
        while(true) {
            getline(cin, dob);
            if(isValidDate(dob))
                break;
            else
                cout << "Invalid date format. Please enter in DD/MM/YYYY format: ";
        }

        cout << "Enter customer balance: ";
        while(!(cin >> balance)) {
            cout << "Invalid input. Please enter a valid integer for balance: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        CustomerLinkedList *newCustomer = new CustomerLinkedList(code, name, dob, balance);
        newCustomer->next = customerHead;
        customerHead = newCustomer;

        cout << "Customer added successfully.\n";
    }

    void addTransaction() {
        int customer_code, amount;
        string type, date;

        // Increment transaction ID
        transactionIDCounter++;

        // Use the auto-incremented transaction ID
        int id = transactionIDCounter;

        // Prompt for deposit or withdrawal using 'd' or 'w'
        while(true) {
            cout << "Enter transaction type (d for Deposit / w for Withdrawal): ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower); // Make input case insensitive

            if(type == "d" || type == "w") {
                if(type == "d") type = "Deposit";
                if(type == "w") type = "Withdrawal";
                break;
            } else {
                cout << "Invalid input. Please enter 'd' for Deposit or 'w' for Withdrawal.\n";
            }
        }

        cout << "Enter customer code: ";
        while(!(cin >> customer_code)) {
            cout << "Invalid input. Please enter a valid integer for customer code: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Check if the customer exists before proceeding with the transaction
        CustomerLinkedList *customer = findCustomerByCode(customer_code);
        if(customer == nullptr) {
            cout << "Customer with code " << customer_code << " does not exist. Transaction cannot be processed.\n";
            return; // Exit the method if the customer doesn't exist
        }

        cout << "Enter transaction amount: ";
        while(!(cin >> amount)) {
            cout << "Invalid input. Please enter a valid integer for amount: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Get current time and format it as DD/MM/YYYY HH:MM:SS
        auto now = chrono::system_clock::now();
        auto time_t_now = chrono::system_clock::to_time_t(now);
        struct tm *time_info = localtime(&time_t_now);

        // Format the date
        stringstream ss;
        ss << put_time(time_info, "%d/%m/%Y %H:%M:%S");
        date = ss.str();

        TransactionLinkedList *newTransaction = new TransactionLinkedList(id, type, customer_code, amount, date);
        newTransaction->next = transactionHead;
        transactionHead = newTransaction;

        // Update customer's balance based on transaction type
        if(type == "Deposit") {
            customer->balance += amount;
            cout << "Deposit successful. Updated balance: " << customer->balance << "\n";
        } else if(type == "Withdrawal") {
            if(customer->balance >= amount) {
                customer->balance -= amount;
                cout << "Withdrawal successful. Updated balance: " << customer->balance << "\n";
            } else {
                cout << "Insufficient balance for withdrawal.\n";
            }
        }

        cout << "Transaction added successfully.\n";
    }

    CustomerLinkedList *findCustomerByCode(int code) {
        CustomerLinkedList *current = customerHead;
        while(current != nullptr) {
            if(current->code == code) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Customer not found
    }

    TransactionLinkedList *findTransactionByID(int id) {
        TransactionLinkedList *current = transactionHead;
        while(current != nullptr) {
            if(current->id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Transaction not found
    }

    void displayCustomerByID() {
        int code;
        cout << "Enter customer code: ";
        while(!(cin >> code)) {
            cout << "Invalid input. Please enter a valid integer for customer code: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        CustomerLinkedList *customer = findCustomerByCode(code);
        if(customer) {
            cout << "Customer Details:\n";
            cout << "Code: " << customer->code << ", Name: " << customer->name
                 << ", DOB: " << customer->dob << ", Balance: " << customer->balance << "\n";
        } else {
            cout << "Customer with code " << code << " not found.\n";
        }
    }

    void displayTransactionByID() {
        int id;
        cout << "Enter transaction ID: ";
        while(!(cin >> id)) {
            cout << "Invalid input. Please enter a valid integer for transaction ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        TransactionLinkedList *transaction = findTransactionByID(id);
        if(transaction) {
            cout << "Transaction Details:\n";
            cout << "ID: " << transaction->id << ", Type: " << transaction->type
                 << ", Customer Code: " << transaction->customer_code << ", Amount: " << transaction->amount
                 << ", Date: " << transaction->date << "\n";
        } else {
            cout << "Transaction with ID " << id << " not found.\n";
        }
    }



    // Function to check the balance of a specific customer
    void checkCustomerBalance() {
        int code;
        cout << "Enter customer code to check balance: ";
        while(!(cin >> code)) {
            cout << "Invalid input. Please enter a valid integer for customer code: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        CustomerLinkedList *customer = findCustomerByCode(code);
        if(customer) {
            cout << "Customer Balance:\n";
            cout << "Code: " << customer->code << ", Name: " << customer->name
                 << ", Balance: " << customer->balance << "\n";
        } else {
            cout << "Customer with code " << code << " not found.\n";
        }
    }

    void displayCustomerMenu() {
        int choice;
        do {
            cout << "\nCustomer Menu\n";
            cout << "1. Display All Customers\n";
            cout << "2. Display Customer by Code\n";
            cout << "3. Check Customer Balance\n";
            cout << "4. Exit to Main Menu\n";
            cout << "Enter your choice: ";
            while(!(cin >> choice)) {
                cout << "Invalid input. Please enter a valid choice: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch(choice) {
            case 1:
                displayCustomers();
                break;
            case 2:
                displayCustomerByID();
                break;
            case 3:
                checkCustomerBalance();
                break;
            case 4:
                cout << "Exiting to main menu.\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
        } while(choice != 4);
    }



    void displayCustomers() {
        if(!customerHead) {
            cout << "No customers to display.\n";
            return;
        }

        CustomerLinkedList *current = customerHead;
        while(current != nullptr) {
            cout << "Code: " << current->code << ", Name: " << current->name
                 << ", DOB: " << current->dob << ", Balance: " << current->balance << "\n";
            current = current->next;
        }
    }

    void displayTransactionMenu() {
        int choice;
        do {
            cout << "\nTransaction Menu\n";
            cout << "1. Display All Transactions\n";
            cout << "2. Display Transaction by ID\n";
            cout << "3. Exit to Main Menu\n";
            cout << "Enter your choice: ";
            while(!(cin >> choice)) {
                cout << "Invalid input. Please enter a valid choice: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch(choice) {
            case 1:
                displayTransactions();
                break;
            case 2:
                displayTransactionByID();
                break;
            case 3:
                cout << "Exiting to main menu.\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
        } while(choice != 3);
    }


    void displayTransactions() {
        if(!transactionHead) {
            cout << "No transactions to display.\n";
            return;
        }

        TransactionLinkedList *current = transactionHead;
        while(current != nullptr) {
            cout << "ID: " << current->id << ", Type: " << current->type
                 << ", Customer Code: " << current->customer_code << ", Amount: " << current->amount
                 << ", Date: " << current->date << "\n";
            current = current->next;
        }
    }

  public:
    // Static initialization of the transaction ID counter
    BankSystem() {
        transactionIDCounter = 0;
    }

    void displayMenu() {
        int choice;

        do {
            cout << "\nBank System Menu\n";
            cout << "1. Add Customer\n";
            cout << "2. Add Transaction\n";
            cout << "3. Display Customers\n";
            cout << "4. Display Transactions\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            while(!(cin >> choice)) {
                cout << "Invalid input. Please enter a valid choice: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch(choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                addTransaction();
                break;
            case 3:
                displayCustomerMenu();
                break;
            case 4:
                displayTransactionMenu();
                break;
            case 5:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
        } while(choice != 5);
    }
};

// Initialize static variable for auto-increment transaction ID
int BankSystem::transactionIDCounter = 0;

int main() {
    BankSystem bankSystem;
    bankSystem.displayMenu();
    return 0;
}
