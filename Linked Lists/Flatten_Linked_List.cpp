#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int value) : data(value), next(nullptr), bottom(nullptr) {}
};

Node* merge(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    return result;
}

Node* flatten(Node* root) {
    if (root == nullptr || root->next == nullptr) {
        return root;
    }
    root->next = flatten(root->next);

    root = merge(root, root->next);

    return root;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    Node* flattened = flatten(head);

    cout << "Flattened Linked List:" << endl;
    printList(flattened);

    return 0;
}
