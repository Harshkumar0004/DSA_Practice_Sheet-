#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList() { head = nullptr; }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtIndex(int index, int val)
    {
        if (index == 0)
        {
            insertAtHead(val);
            return;
        }

        Node *temp = head;
        int count = 0;
        while (temp != nullptr && count < index - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            cout << "Index out of range" << endl;
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int n)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == n)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted!!" << endl;
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        while (temp != nullptr && temp->data != n)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node does not exist!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Node deleted!!" << endl;
    }

    void search(int n)
    {
        if (!head)
        {
            cout << "Empty List !!" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            if (temp->data == n)
            {
                cout << "Found Data !!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found !!" << endl;
        return;
    }

    void countnode(Node *head)
    {
        Node *temp = head;
        int cnt = 0;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        cout << "Number of Nodes are :" << cnt << endl;
        return;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next; // store next
            current->next = prev; // reverse link
            prev = current;       // move prev ahead
            current = next;       // move current ahead
        }
        head = prev; // new head
        cout << "Linked List Reversed Successfully!!" << endl;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    //delete duplicates from sorted list-------------------------------->
    void deleteDuplicates()
    {
        Node *current = head;

        while (current && current->next)
        {
            if (current->data == current->next->data)
            {
                Node *dup = current->next;
                current->next = current->next->next;
                delete dup;
            }
            else
            {
                current = current->next;
            }
        }

        cout << "Duplicates removed successfully!!" << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original List: ";
    list.display();

    list.deleteDuplicates();
    cout << "After removing duplicates: ";
    list.display();
}