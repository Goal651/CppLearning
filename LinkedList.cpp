#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() {}
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *addAtHead(Node *head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

Node *newNode(Node *head, int data)
{
    Node *temp = new Node(data);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
};

int main()
{

    Node *root = new Node();
    Node *second = new Node();
    Node *third = new Node();

    root->data = 10;
    root->next = second;
    second->data = 20;
    second->next = third;
    third->data = 40;

    display(root);

    root = addAtHead(root, 300);
    display(root);

    root = newNode(root, 500);
    display(root);
    return 0;
}
