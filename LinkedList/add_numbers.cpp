#include <iostream>
#include<vector>
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
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtIndex(int index, int val) {
        if (index == 0) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        int count = 0;
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

    //delete a node------------------------>

    void deleteNode(int n) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == n) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted!!" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != n) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node does not exist!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Node deleted!!" << endl;
    }
    //count method for middle find-------------------------->
    // int countnode(Node *head)
    // {
    //     Node *temp = head;
    //     int cnt = 0;
    //     while (temp)
    //     {
    //         cnt++;
    //         temp = temp->next;
    //     }
    //     return cnt;
    // }
    // Node* midlist(){
    //     int n=(countnode(head)/2)+1;
    //     Node* temp=head;
    //     while(n>1){
    //         temp=temp->next;
    //         n--;
    //     }
    //     return temp;
    // }


    //middle of list----------------------------------------->

    Node *midoflist()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
//add number------------------------------------------------->
    Node *addnum(Node *l1, Node *l2)
    {
        vector<int> e1, e2;
        Node *temp1 = l1;
        while (temp1)
        {
            e1.push_back(temp1->data);
            temp1 = temp1->next;
        }

        Node *temp2 = l2;
        while (temp2)
        {
            e2.push_back(temp2->data);
            temp2 = temp2->next;
        }

        int n = e1.size();
        int m = e2.size();
        int i = 0, j = 0, carry = 0;

        Node *dummy = new Node(0);
        Node *curr = dummy;

        while (i < n || j < m || carry)
        {
            int x = (i < n) ? e1[i] : 0;
            int y = (j < m) ? e2[j] : 0;

            int s = x + y + carry;
            carry = s / 10;

            curr->next = new Node(s % 10);
            curr = curr->next;

            i++;
            j++;
        }

        return dummy->next;
    }

    // Node* addnum(Node *l1, Node *l2)
    // {
    //     Node *dummy = new Node(0);
    //     Node *current = dummy;
    //     int carry = 0;

    //     while (l1 || l2 || carry)
    //     {
    //         int sum = carry;

    //         if (l1)
    //         {
    //             sum += l1->data;
    //             l1 = l1->next;
    //         }

    //         if (l2)
    //         {
    //             sum += l2->data;
    //             l2 = l2->next;
    //         }

    //         carry = sum / 10;
    //         current->next = new Node(sum % 10);
    //         current = current->next;
    //     }

    //     return dummy->next;
    // }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    Node *getHead()
    {
        return head;
    }
};

int main() {
    LinkedList list1, list2;

    list1.insertAtEnd(2);
    list1.insertAtEnd(4);
    list1.insertAtEnd(3);

    list2.insertAtEnd(5);
    list2.insertAtEnd(6);
    list2.insertAtEnd(4);

    Node* result = list1.addnum(list1.getHead(), list2.getHead());

    cout << "Sum list: ";
    while (result) {
        cout << result->data << " -> ";
        result = result->next;
    }
    cout << "NULL" << endl;

    return 0;
}


