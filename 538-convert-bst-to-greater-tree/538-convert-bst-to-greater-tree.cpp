class Solution {
public:
    int sum = 0;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->right);
        sum+=root->val;
        root->val=sum;
        helper(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};