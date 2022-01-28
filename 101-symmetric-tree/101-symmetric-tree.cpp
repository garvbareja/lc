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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1,q2;
        q1.push(root->left); q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            TreeNode* lfront = q1.front(); q1.pop();
            TreeNode* rfront = q2.front(); q2.pop();
            if(lfront && rfront){
                if(lfront->val!=rfront->val) return false;
                q1.push(lfront->left);
                q1.push(lfront->right);
                q2.push(rfront->right);
                q2.push(rfront->left);
            }else{
                if(lfront || rfront) return false;
            }
        }
        return true;
    }
};