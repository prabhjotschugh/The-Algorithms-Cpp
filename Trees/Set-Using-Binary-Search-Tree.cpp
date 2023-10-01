// Implementation Of Set Using Binary Search Tree

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// TreeNode Implementation

class Node{
public:
    int val;
    Node* left, *right;
    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};


// TreeSet implementation

class TreeSet{
public:
    Node* root; // root of the tree

    TreeSet(Node* r){
        root = r;
    }

    // value insertion O(log n)

    void insert(int value){
        Node* neww = new Node(value);
        Node* x = root;
        while(x->val != value){
            if(value > x->val){
                if(!x->right)break;
                x = x->right;
            }
            else{
                if(!x->left)break;
                x = x->left;
            } 
        }
        if(x->val == value)return;
        if(x->val > value)x->left = neww;
        else x->right = neww;
    }

    // search in O(log n)

    bool search(int value){
        Node* cur = root;
        while(cur){
            if(cur->val == value)return true;
            if(cur->val > value)cur = cur->left;
            else cur = cur->right;
        }

        return false;
    }
    

    // dfs function

    void dfs(Node* root){
        if(!root)return;
        dfs(root->left);
        cout << root->val << " ";
        dfs(root->right);
    }

    // prints set in order O(n)

    void print(){
        Node* cur = root;
        dfs(cur);
        cout << "\n";
    }

};

// union method O(n*log m)

// makes a copy of a tree
void dfs(Node* root, TreeSet* st){
    if(!root)return;
    st->insert(root->val);
    dfs(root->left, st);
    dfs(root->right, st);
}

TreeSet* deepcopy(TreeSet* st){
    TreeSet* neww = new TreeSet(new Node(st->root->val));
    dfs(st->root, neww);
    return neww;
}

// union function
TreeSet* uni(TreeSet* st1, TreeSet* st2){
    TreeSet* st3 = deepcopy(st1);
    dfs(st2->root, st3);
    return st3;
} 



// intersection method O(n*log m)

// finds common nodes between two trees
void findCommon(Node* root, vector<int> &common, TreeSet* st2){
    if(!root)return;
    if(st2->search(root->val))common.push_back(root->val);
    findCommon(root->left, common, st2);
    findCommon(root->right, common, st2);
}

// intersection function
TreeSet* intersection(TreeSet* st1, TreeSet* st2){
    vector<int> common;
    findCommon(st1->root, common, st2);
    if(common.empty())return nullptr;
    TreeSet* neww = new TreeSet(new Node(common[0]));
    for(int i=1; i<common.size(); ++i)neww->insert(common[i]);
    return neww;
}



void solve()
{
    // declaring the sets
    Node* head1 = new Node(100);
    Node* head2 = new Node(329);
    TreeSet* set1 = new TreeSet(head1);
    TreeSet* set2 = new TreeSet(head2);
    
    // first set insertion
    set1->insert(80);
    set1->insert(120);
    set1->insert(30);
    set1->insert(90);
    set1->insert(200);
    set1->insert(200);

    // second set insertion
    set2->insert(186);
    set2->insert(120);
    set2->insert(500);
    set2->insert(432);
    set2->insert(20);
    set2->insert(30);
    
    // union
    TreeSet* union1 = uni(set1, set2);
    union1->print(); // 30 & 120 common in 2 sets but uni function unites them and removes duplicates
    
    // intersection
    TreeSet* intersection1 = intersection(set1, set2);
    intersection1->print(); // 30 & 120 is common and intersection function prints exactly the same
}

/* Main()  function */

int main()
{
    solve();
    return 0;
}