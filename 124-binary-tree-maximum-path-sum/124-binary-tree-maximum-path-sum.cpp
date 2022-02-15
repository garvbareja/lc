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
    int dfs(TreeNode* root){
        if(!root) return 0;
        int ls=dfs(root->left);
        int rs=dfs(root->right);
        int ret=max(root->val,root->val+max(ls,rs));
        ans=max(ans,max(ret,root->val+ls+rs));
        return ret;
    }
    
    int maxPathSum(TreeNode* root){
        ans=root->val;
        dfs(root);
        return ans;
    }
};