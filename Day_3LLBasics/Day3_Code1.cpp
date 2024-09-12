#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int length(Node* head) {
    Node* temp = head;
    int len = 0;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtPos(Node*& head, int data, int pos) {
    if (pos <= 1) {
        insertAtHead(head, data);
    } else if (pos >= length(head) + 1) {  // inserting at tail if position is out of range
        insertAtTail(head, data);
    } else {
        Node* newNode = new Node(data);
        Node* temp = head;
        int cnt = 1;

        // Traverse till the node just before the desired position
        while (cnt < pos - 1) {
            temp = temp->next;
            cnt++;
        }
        
        // Insert the node at the given position
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtHead(head, 10);
    insertAtHead(head, 5);
    insertAtTail(head, 20);
    insertAtPos(head, 15, 3);
    
    printList(head); 

    return 0;
}
