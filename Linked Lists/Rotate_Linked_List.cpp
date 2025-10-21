// Rotate_Linked_List.cpp
// Rotate a linked list right by k positions
// Example: 1 -> 2 -> 3 -> 4 -> 5, k = 2 → 4 -> 5 -> 1 -> 2 -> 3

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length of the list
        ListNode* curr = head;
        int length = 1;
        while (curr->next) {
            curr = curr->next;
            length++;
        }

        // Step 2: Make it circular
        curr->next = head;

        // Step 3: Find the new head after rotation
        k = k % length; // In case k > length
        int stepsToNewHead = length - k;

        ListNode* newTail = curr; // reuse curr pointer
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        // Step 4: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};

// Helper functions for testing
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Example run
int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(vals);
    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "Rotated List by " << k << " nodes: ";
    printList(head);

    return 0;
}
