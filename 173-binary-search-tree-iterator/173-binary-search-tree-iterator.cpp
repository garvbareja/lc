/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    void goleft(TreeNode* root){
        if(!root) return;
        while(root->left){
            s.push(root);
            root=root->left;
        }
        s.push(root);
    }
    
    BSTIterator(TreeNode* root) {
        goleft(root);
    }
    
    int next() {
        int res=s.top()->val;
        TreeNode* temp=s.top(); s.pop();
        goleft(temp->right);
        return res;
    }
    
    bool hasNext() {
        return s.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */