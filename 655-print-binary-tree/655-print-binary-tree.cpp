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
    vector<vector<string>> ans;
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void help(TreeNode* root,int low,int high,int level){
        if(!root) return;
        if(low>high) return;
        int mid = low + (high-low)/2;
        ans[level][mid]=to_string(root->val);
        help(root->left,low,mid-1,level+1);
        help(root->right,mid+1,high,level+1);
    }
    
    vector<vector<string>> printTree(TreeNode* root){
        int h = height(root);
        int c = pow(2,h)-1;
        ans.resize(h,vector<string>(c));
        help(root,0,c-1,0);
        return ans;
    }
};