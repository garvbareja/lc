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
    bool flag=true;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int lh=dfs(root->left);
        if(lh==-1) return -1;
        int rh=dfs(root->right);
        if(rh==-1) return -1;
        if(flag){
            if(abs(lh-rh)>1){
                flag=false;
                return -1;
            }
        }else return -1;
        return 1+max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};