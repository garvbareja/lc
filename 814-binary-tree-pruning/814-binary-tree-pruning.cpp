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
    bool help(TreeNode* root){
        if(!root) return false;
        bool l = help(root->left);
        bool r = help(root->right);
        if(!l) root->left=nullptr; if(!r) root->right=nullptr;
        return root->val || l || r;
    }
    
    TreeNode* pruneTree(TreeNode* root){
       if(!help(root)) return nullptr;
        return root;
    }
};