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
    void flatten(TreeNode* root){
        TreeNode* res = root;
        stack<TreeNode*> s;
        while(root){
            if(root->right) s.push(root->right);
            if(root->left) root->right=root->left;
            else{
                if(s.empty()) break;
                root->right=s.top(); s.pop();
            }
            root->left=nullptr;
            root=root->right;
        }
    }
};