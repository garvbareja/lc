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
    int ans=0;
    void dfs(TreeNode* root,int curmax){
        if(root->val>=curmax) ans++;
        if(root->left) dfs(root->left,max(root->val,curmax));
        if(root->right) dfs(root->right,max(root->val,curmax));
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root,-10000001);
        return ans;
    }
};