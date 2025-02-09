#include <iostream>
using namespace std;

struct Queue {
    int size, front, rear;
    int* array; 

    Queue(int s) {
        size = s;
        front = rear = -1;
        array = new int[size]; 
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        array[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return array[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // Output: 10 20 30

    cout << "Dequeued: " << q.dequeue() << endl;

    q.display(); // Output: 20 30

    return 0;
}
