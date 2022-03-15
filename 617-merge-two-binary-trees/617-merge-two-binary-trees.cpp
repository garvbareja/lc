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
    TreeNode* dfs(TreeNode* p,TreeNode* q){
        if(!p) return q;
        if(!q) return p;
        p->val+=q->val;
        p->left=dfs(p->left,q->left);
        p->right=dfs(p->right,q->right);
        return p;
    }
    
    TreeNode* mergeTrees(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};