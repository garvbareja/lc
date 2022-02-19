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
    void dfs(TreeNode* root,int mx,int mn){
        if(!root) return;
        ans=max(ans,max(abs(root->val-mx),abs(root->val-mn)));
        mx=max(mx,root->val); mn=min(mn,root->val);
        dfs(root->left,mx,mn); dfs(root->right,mx,mn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return ans;
    }
};