#include <iostream>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to insert at the end of the doubly linked list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the doubly linked list
Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;  // Empty or 1 node

    Node* curr = head;
    Node* temp = nullptr;

    // Swap next and prev for all nodes
    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; // Move to next node (which is prev now)
    }

    // After reversing, temp will be at the node before NULL, so fix head
    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;
}

// Main function
int main() {
    Node* head = nullptr;

    // Create the doubly linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original Doubly Linked List: ";
    printList(head);

    // Reverse the DLL
    head = reverseDLL(head);

    cout << "Reversed Doubly Linked List: ";
    printList(head);

    return 0;
}
