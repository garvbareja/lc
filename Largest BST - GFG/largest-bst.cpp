// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class custom_data{
public:
    bool isBST;
    int mx;
    int mn;
    int size;
    custom_data(){
        isBST=true;
        mx=INT_MIN;
        mn=INT_MAX;
        size=0;
    }
};

class Solution{
    public:
    int ans=1;
    custom_data dfs(Node* root){
        custom_data res;
        if(!root) return res;
        custom_data left=dfs(root->left);
        custom_data right=dfs(root->right);
        res.isBST=left.isBST && right.isBST && root->data>left.mx && root->data<right.mn;
        if(res.isBST){
            res.size=left.size+right.size+1;
            res.mx=max(root->data,max(right.mx,left.mx));
            res.mn=min(root->data,min(left.mn,right.mn));
            ans=max(ans,res.size);
        }else{
            res.isBST=false;
            res.size=1;
            res.mn=INT_MIN;
            res.mx=INT_MAX;
        }
        return res;
    }
    
    int largestBst(Node *root)
    {
    	dfs(root);
    	return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends