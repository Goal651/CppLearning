#include <iostream>
using namespace std;

struct PriorityQueue {
    int size, count;
    int* queue;

    // Constructor
    PriorityQueue(int s) {
        size = s;
        count = 0;
        queue = new int[size];
    }

    // Destructor
    ~PriorityQueue() {
        delete[] queue;
    }

    // Insert element at the end (O(1))
    void enqueue(int value) {
        if (count == size) {
            cout << "Queue Overflow\n";
            return;
        }
        queue[count++] = value;
    }

    // Find and remove the highest-priority element (O(n))
    int dequeue() {
        if (count == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }

        // Find the highest-priority element (max value)
        int maxIndex = 0;
        for (int i = 1; i < count; i++) {
            if (queue[i] > queue[maxIndex]) {
                maxIndex = i;
            }
        }

        int highestPriority = queue[maxIndex];

        // Shift elements left to fill the gap
        for (int i = maxIndex; i < count - 1; i++) {
            queue[i] = queue[i + 1];
        }
        count--;

        return highestPriority;
    }

    // Display elements
    void display() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < count; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

// Main function to test priority queue
int main() {
    PriorityQueue pq(5);

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(50);
    pq.enqueue(40);
    pq.enqueue(20);

    pq.display(); // Output: 30 10 50 40 20

    cout << "Dequeued: " << pq.dequeue() << endl; // Removes 50
    pq.display(); // Output: 30 10 40 20

    return 0;
}
