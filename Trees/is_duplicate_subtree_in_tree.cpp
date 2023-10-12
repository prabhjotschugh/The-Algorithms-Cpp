#include <bits/stdc++.h>
using namespace std;
struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};
//code for building tree
struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;
	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;
	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);
	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));
	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);
	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {
		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();
		// Get the current node's value from the string
		string currVal = ip[i];
		// If the left child is not null
		if (currVal != "N") {
			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));
			// Push it to the queue
			queue.push(currNode->left);
		}
		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];
		// If the right child is not null
		if (currVal != "N") {
			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));
			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}
	return root;
}
class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         unordered_map<string,int>mp;
         queue<Node*>q;
         q.push(root);
         int cnt=0;
         while(!q.empty()){
             Node*temp=q.front();q.pop();
             string t;
             cnt=0;
             bool fg=true;
             t.push_back(temp->data+'0');
             if(temp->left){
                 q.push(temp->left);
                 t.push_back(temp->left->data+'0');
                 cnt++;
                 if(temp->left->left!=NULL||temp->left->right!=NULL)
                 fg=false;
             }
             else
             t.push_back('@');
             if(temp->right){
                 q.push(temp->right);
                 t.push_back(temp->right->data+'0');
                 cnt++;
                 if(temp->right->left!=NULL||temp->right->right!=NULL)
                 fg=false;
             }
             else
             t.push_back('@');
             if(t.size()>1&&cnt>0&&fg&&mp.find(t)!=mp.end())return true;
             else if(t.size()>1&&cnt>0&&fg) mp[t]++;
             //string tt;
             t="";
         }
         return false;
    }
};
int main()
{	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
