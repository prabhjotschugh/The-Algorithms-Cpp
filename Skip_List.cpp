// Skip_List.cpp
// Implementation of a simple Skip List data structure
// Used in databases like Redis for fast search, insertion, and deletion
// Concept: probabilistic multi-level linked list with express lanes

#include <bits/stdc++.h>
using namespace std;

// Maximum levels allowed in Skip List
#define MAX_LEVEL 6

// Probability factor for random level generation
#define P 0.5

// Node structure
struct Node {
    int val;
    vector<Node*> forward;
    Node(int val, int level) : val(val), forward(level + 1, nullptr) {}
};

// Skip List class
class SkipList {
    int level;
    Node* header;

public:
    SkipList() {
        level = 0;
        header = new Node(-1, MAX_LEVEL); // header node
    }

    // Generate a random level for node
    int randomLevel() {
        int lvl = 0;
        while (((double)rand() / RAND_MAX) < P && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

    // Insert a value into the skip list
    void insertElement(int val) {
        vector<Node*> update(MAX_LEVEL + 1, nullptr);
        Node* curr = header;

        // Move down levels to find insertion point
        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < val)
                curr = curr->forward[i];
            update[i] = curr;
        }

        curr = curr->forward[0];

        if (curr == nullptr || curr->val != val) {
            int rlevel = randomLevel();

            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++)
                    update[i] = header;
                level = rlevel;
            }

            Node* n = new Node(val, rlevel);

            for (int i = 0; i <= rlevel; i++) {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }

            cout << "Inserted: " << val << " (Level " << rlevel << ")\n";
        }
    }

    // Search for a value
    bool searchElement(int val) {
        Node* curr = header;
        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < val)
                curr = curr->forward[i];
        }
        curr = curr->forward[0];
        return curr && curr->val == val;
    }

    // Delete a value
    void deleteElement(int val) {
        vector<Node*> update(MAX_LEVEL + 1, nullptr);
        Node* curr = header;

        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < val)
                curr = curr->forward[i];
            update[i] = curr;
        }

        curr = curr->forward[0];
        if (curr && curr->val == val) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != curr) break;
                update[i]->forward[i] = curr->forward[i];
            }

            delete curr;

            while (level > 0 && header->forward[level] == nullptr)
                level--;

            cout << "Deleted: " << val << "\n";
        }
    }

    // Display the Skip List
    void displayList() {
        cout << "\n***** Skip List *****\n";
        for (int i = level; i >= 0; i--) {
            Node* node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << node->val << " ";
                node = node->forward[i];
            }
            cout << "\n";
        }
    }
};

// Example run
int main() {
    srand(time(NULL));
    SkipList sl;

    sl.insertElement(3);
    sl.insertElement(6);
    sl.insertElement(7);
    sl.insertElement(9);
    sl.insertElement(12);
    sl.insertElement(19);

    sl.displayList();

    cout << "\nSearching for 9 → " << (sl.searchElement(9) ? "Found" : "Not Found") << endl;
    cout << "Searching for 15 → " << (sl.searchElement(15) ? "Found" : "Not Found") << endl;

    sl.deleteElement(6);
    sl.displayList();

    return 0;
}
