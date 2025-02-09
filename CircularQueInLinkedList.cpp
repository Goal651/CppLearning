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
    Node *front;
    Node *rear;
    Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL && rear == NULL;
    }

    void enqueue(int value)
    {
        Node *temp = new Node(value);
        if (isEmpty())
        {
            front = temp;
            rear = temp;
            rear->next = front;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    void display()
    {
        Node *temp = front;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        while (temp != rear)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
