#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void display(Node *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *n1 = new Node(55);
    Node *n2 = new Node(66);
    Node *n3 = new Node(77);
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    display(n1);

    return 0;
}