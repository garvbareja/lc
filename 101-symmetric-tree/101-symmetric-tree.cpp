class Solution {
public:
    bool dfs(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val==q->val && dfs(p->left,q->right) && dfs(p->right,q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};