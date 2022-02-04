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
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> q; q.push(root); int val=root->val;
        while(!q.empty()){
            TreeNode* front = q.front(); q.pop();
            if(front->val!=val) return false;
            if(front->right) q.push(front->right);
            if(front->left) q.push(front->left);
        }
        return true;
    }
};