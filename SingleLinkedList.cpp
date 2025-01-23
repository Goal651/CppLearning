#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() {};
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void displayNodes(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *addNewNode(Node *head, int data)
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

Node *addFirstNode(int data)
{
    Node *newNode = new Node(data);
    return newNode;
}

Node *addNodeAtHead(Node *head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

Node *adAtAnyPost(Node *head, int pos, int data)
{
    if (pos < 0)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    int count = 1;

    while (count <= pos - 1 && head != NULL)
    {
        head = head->next;
        count++;
    }
    if (head)
    {
        Node *tempNode = new Node(data);
        tempNode->next = head->next;
        head->next = tempNode;
        return temp;
    }
    return temp;
}

int searchNode(Node *head, int key)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

Node *deleteFirstNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = temp->next;
    delete temp;
    return head;
}

Node *deleteLastNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node *deleteNode(Node *head, int pos)
{
    if (head == NULL || pos < 1)
    {
        return head;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        return head;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}

int main()
{
    Node *n1 = addFirstNode(500);
    displayNodes(n1);
    addNewNode(n1, 555);
    displayNodes(n1);
    Node *newHead = addNodeAtHead(n1, 4444);
    displayNodes(newHead);
    Node *newNid = adAtAnyPost(newHead, 0, 5000);
    displayNodes(newNid);
    int index = searchNode(newNid, 000);
    cout << "Index index " << index << endl;
    newNid = deleteFirstNode(newNid);
    displayNodes(newNid);
    newNid = deleteLastNode(newNid);
    displayNodes(newNid);
    return 0;
}