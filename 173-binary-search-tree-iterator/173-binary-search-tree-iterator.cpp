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
    TreeNode* root;
    BSTIterator(TreeNode* node) {
        root=node;
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    
    int next(){
        int ret;
        if(!root){
            ret=s.top()->val;
            root=s.top()->right;
            s.pop();
        }
        while(root){
            s.push(root);
            root=root->left;
        }
        return ret;
    }
    
    bool hasNext() {
        return root||!s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */