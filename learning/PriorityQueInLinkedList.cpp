#include <iostream>
using namespace std;

// Node structure for the priority queue
struct Node
{
    int data, priority;
    Node *next;

    Node(int d, int p)
    {
        data = d;
        priority = p;
        next = nullptr;
    }
};

// Priority Queue class
class PriorityQueue
{
private:
    Node *front; // Points to the highest-priority node

public:
    PriorityQueue()
    {
        front = nullptr;
    }

    // Insert node based on priority
    void enqueue(int data, int priority)
    {
        Node *newNode = new Node(data, priority);

        // Case 1: Insert at the front (if empty or highest priority)
        if (!front || priority > front->priority)
        {
            newNode->next = front;
            front = newNode;
            return;
        }

        // Case 2: Traverse and find the correct position
        Node *temp = front;
        while (temp->next && temp->next->priority >= priority)
        {
            temp = temp->next;
        }

        // Insert new node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove and return the highest-priority element
    int dequeue()
    {
        if (!front)
        {
            cout << "Queue Underflow\n";
            return -1;
        }

        Node *temp = front;
        front = front->next;
        int value = temp->data;
        delete temp;
        return value;
    }

    // Display the queue
    void display()
    {
        if (!front)
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        cout << "Priority Queue: ";
        while (temp)
        {
            cout << "(" << temp->data << ", P" << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test the priority queue
int main()
{
    PriorityQueue pq;

    pq.enqueue(30, 2);
    pq.enqueue(10, 1);
    pq.enqueue(50, 3);
    pq.enqueue(40, 2);
    pq.enqueue(20, 4);

    pq.display(); // Output: (20, P4) (50, P3) (30, P2) (40, P2) (10, P1)

    cout << "Dequeued: " << pq.dequeue() << endl; // Removes 20 (highest priority)
    pq.display();                                 // Updated queue

    return 0;
}
