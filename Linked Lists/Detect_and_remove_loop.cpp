#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to detect and remove loop in a linked list
void detectAndRemoveLoop(Node* head) {
    if (!head || !head->next) {
        return; // No loop if the list is empty or has only one node
    }

    Node *slow = head, *fast = head;

    // Step 1: Detect Loop using Floyd's Cycle Detection Algorithm
    while (fast && fast->next) {
        slow = slow->next;         // Move slow pointer by 1
        fast = fast->next->next;   // Move fast pointer by 2

        if (slow == fast) {
            break; // Loop detected
        }
    }

    // No loop found
    if (slow != fast) {
        return;
    }

    // Step 2: Find the starting point of the loop
    slow = head;
    Node* prev = nullptr; // To keep track of the last node before the loop starts
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove the loop
    prev->next = nullptr; // Break the loop by setting the next of the last node to null
}

// Helper function to insert a node at the end of the linked list
void insertNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Test code
int main() {
    Node* head = nullptr;
    
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    
    // Creating a loop: 5 -> 3 (making the next of 5 as 3)
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head); // Detect and remove the loop

    // Print the list after loop removal
    printList(head); // Output should be 1 2 3 4 5
    
    return 0;
}
