#include <iostream>
#include <string>
using namespace std;

// Node structure for the priority queue (Student details)
struct Student {
    int code, age;
    string name;
    Student* next;

    Student(int c, string n, int a) {
        code = c;
        name = n;
        age = a;
        next = nullptr;
    }
};

// Priority Queue class for students
class StudentPriorityQueue {
private:
    Student* front; // Points to the student with the highest priority (oldest)

public:
    StudentPriorityQueue() {
        front = nullptr;
    }

    // Insert student based on age (higher age = higher priority)
    void enqueue(int code, string name, int age) {
        Student* newStudent = new Student(code, name, age);

        // Case 1: Insert at the front (if empty or highest priority)
        if (!front || age > front->age) {
            newStudent->next = front;
            front = newStudent;
            return;
        }

        // Case 2: Traverse and find the correct position
        Student* temp = front;
        while (temp->next && temp->next->age >= age) {
            temp = temp->next;
        }

        // Insert new student
        newStudent->next = temp->next;
        temp->next = newStudent;
    }

    // Remove and return the student with the highest priority (oldest)
    void dequeue() {
        if (!front) {
            cout << "Queue Underflow - No students in the queue\n";
            return;
        }

        Student* temp = front;
        front = front->next;
        cout << "Removed: " << temp->name << " (Code: " << temp->code << ", Age: " << temp->age << ")\n";
        delete temp;
    }

    // Display the queue
    void display() {
        if (!front) {
            cout << "Queue is empty\n";
            return;
        }

        Student* temp = front;
        cout << "Priority Queue (Oldest to Youngest):\n";
        while (temp) {
            cout << "Code: " << temp->code << ", Name: " << temp->name << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }
};

// Main function to test the priority queue
int main() {
    StudentPriorityQueue pq;

    // Adding students
    pq.enqueue(101, "Alice", 22);
    pq.enqueue(102, "Bob", 19);
    pq.enqueue(103, "Charlie", 24);
    pq.enqueue(104, "David", 21);
    pq.enqueue(105, "Eve", 23);

    // Displaying queue
    pq.display();

    // Dequeue highest-priority student (oldest)
    cout << "\nDequeue Operation:\n";
    pq.dequeue();
    pq.display();

    return 0;
}
