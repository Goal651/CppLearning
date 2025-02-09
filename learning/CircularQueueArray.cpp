#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;

    Queue(int s)
    {
        size = s;
        front = rear = -1;
        Q = new int[size];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            return true;
        else
            return false;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "\nQueue Overflow \n";
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            Q[rear] = x;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            Q[rear] = x;
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            exit(1);
        }
        int x = Q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front++;
        return x;
    }

    void display()
    {
        int i = front;
        if (front <= rear)
        {
            while (i <= rear)
            {
                cout << Q[i] << " ";
                i++;
            }
        }
        else
        {
            while (i <= size - 1)
            {
                cout << Q[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                cout << Q[i] << " ";
                i++;
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}