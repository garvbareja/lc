/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans=nullptr;
    TreeNode* x; TreeNode* y;
    bool dfs(TreeNode* root){
        if(!root) return false;
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if(left&&right || left&&(root==x||root==y) || right&&(root==x||root==y)) ans=root;
        return root==x||root==y||left||right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        x=p; y=q;
        dfs(root);
        return ans;
    }
};