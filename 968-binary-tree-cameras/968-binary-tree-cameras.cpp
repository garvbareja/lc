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
    int c =0;
    int dfs(TreeNode* root){
        if(!root->left && !root->right) return 0;
        int leftans=2,rightans=2;
        if(root->left) leftans=dfs(root->left);
        if(root->right) rightans=dfs(root->right);
        if(!leftans || !rightans){
            c++; return 1;
        }
        if(leftans==1 || rightans==1) return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(!dfs(root)) c++;
        return c;
    }
};