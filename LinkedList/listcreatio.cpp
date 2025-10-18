#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class LinkedList {
    Node* head;

public:
    LinkedList() { head = nullptr; }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head; // link new node to old head
        head = newNode;       // move head to new node
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {  // if list is empty
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtIndex(int index, int val) {
        if (index == 0) {  // special case: insert at head
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        int count = 0;

        // traverse till node just before desired index
        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Index out of range" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();  // 10 -> 20 -> 30 -> NULL

    list.insertAtHead(5);
    list.display();  // 5 -> 10 -> 20 -> 30 -> NULL

    list.insertAtIndex(2, 15);
    list.display();  // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    list.insertAtIndex(0, 1);
    list.display();  // 1 -> 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    list.insertAtIndex(10, 100); // invalid 
}
