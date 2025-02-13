#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void displayLinkedList(Node *node)
{
    Node *temp = node;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *addToHead(Node *node, int data)
{
    Node *newNode = new Node(data);
    if (node == NULL)
    {
        node = newNode;
        return node;
    }
    newNode->next = node;
    node = newNode;
    return node;
}

Node *addNewNode(Node *node, int data)
{
    Node *newNode = new Node(data);
    if (node == NULL)
    {
        node = newNode;
        return node;
    }

    Node *temp = node;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return node;
}

Node *deleteHead(Node *node)
{
    if (node == NULL)
    {
        cout << "Linked list empty" << endl;
        return NULL;
    }
    if (node->next == NULL)
    {
        delete node;
        return NULL;
    }
    Node *temp = node;
    node = temp->next;
    delete temp;
    return node;
}

Node *deleteTail(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->next == NULL)
    {
        delete node;
        return NULL;
    }

    Node *temp = node;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return node;
}

void searchNode(Node *node, int data)
{
    int i = 0;
    Node *temp = node;
    while (temp)
    {

        if (temp->data == data)
        {
            cout << "The node containing data " << data << " is on index " << i << endl;
            return;
        }
        i++;
        temp = temp->next;
    }

    cout << "Node containing data " << data << " not found" << endl;
}

Node *addNodeToPos(Node *node, int data, int pos)
{
    Node *newNode = new Node(data);
    if (pos <= 0)
    {
        cout << "That position don't exist" << endl;
        return node;
    }
    if (node == NULL)
    {
        if (pos != 0)
        {
            cout << "That position don't exist" << endl;
            return node;
        }
        node = newNode;
        return node;
    }

    int checker = 0;
    Node *temp = node;
    while (temp && pos > checker)
    {
        temp = temp->next;
        checker++;
    }
    if (temp == NULL)
    {
        cout << "That position don't exist" << endl;
        return node;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return node;
}

Node *deleteAtPos(Node *node, int pos)
{
    if (pos < 0)
    {
        cout << "That position don't exist" << endl;
        return node;
    }
    if (node == NULL)
    {
        if (pos != 0)
        {
            cout << "That position don't exist" << endl;
            return node;
        }
        return node;
    }
    if (pos == 0)
    {
        if (node == NULL)
        {
            cout << "That position don't exist" << endl;
            return node;
        }
        return deleteHead(node);
    }

    int checker = 0;
    Node *temp = node;
    while (temp && pos - 1 > checker)
    {
        temp = temp->next;
        checker++;
    }

    if (temp->next == NULL)
    {
        cout << "That position don't exist" << endl;
        return node;
    }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    return node;
}

int main()
{
    // initialize linked linkedlist
    Node *node = new Node();

    // adding nodes
    displayLinkedList(node);
    node = addToHead(node, 10);
    displayLinkedList(node);
    node = addToHead(node, 30);
    displayLinkedList(node);
    node = addToHead(node, 20);
    displayLinkedList(node);
    node = addNodeToPos(node, 100, 2);
    displayLinkedList(node);
    node = addNewNode(node, 999);
    displayLinkedList(node);
    // deleting nodes
    node = deleteHead(node);
    displayLinkedList(node);
    node = deleteTail(node);
    displayLinkedList(node);
    searchNode(node, 10);
    node = deleteAtPos(node, 2);
    displayLinkedList(node);
}