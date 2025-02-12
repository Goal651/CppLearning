#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

struct Queue
{
    Node *rear;
    Node *front;
    Node *newNode;
    Queue()
    {
        rear = NULL;
        front = NULL;
        newNode = NULL;
    }

    bool isEmpty()
    {
        return rear == NULL && front == NULL;
    }

    void enqueue(int value)
    {
        newNode = new Node(value);
        if (rear == NULL)
        {
            rear = newNode;
            front = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear)
        {

            front = NULL;
            rear = NULL;
            delete front;
            delete rear;
        }

        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void display()
    {
        Node *temp = front;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    for (int i = 40; i < 50; i++)
    {
        q.enqueue(i);
    }

    q.display();
    for (int i = 0; i < 5; i++)
    {
        q.dequeue();
    }

    cout << "Dequeued: " << endl;

    q.display();

    return 0;
}
