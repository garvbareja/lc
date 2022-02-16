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
class Solution {
public:
    void recoverTree(TreeNode* root){
        TreeNode* prev=nullptr;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top(); s.pop();
            if(prev && prev->val>=root->val && !first) first=prev; 
            if(prev && prev->val>=root->val && first) second=root;
            prev=root;
            root=root->right;
        }
        swap(first->val,second->val);
    }
};