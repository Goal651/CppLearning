#include <iostream>
using namespace std;

//class for queue
struct Queue {
    int size, front, rear;
    int* array; 

    //constructor for queue 
    Queue(int s) {
        size = s;
        front = rear = -1;
        array = new int[size]; 
    }

    //function to check if queue is full
    bool isFull() {
        return rear == size - 1;
    }

    //function to check if queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    //function to enqueue element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        array[++rear] = value;
    }

    //function to dequeue element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return array[front++];
    }

    //function to display elements
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
    Queue q(5); 
    //enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();       //output 10 20 30
    cout << "Dequeued: " << q.dequeue() << endl; //output 10
    q.display();       //output 20 30
    return 0;
}
