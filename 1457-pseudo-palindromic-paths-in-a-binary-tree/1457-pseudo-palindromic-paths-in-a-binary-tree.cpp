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
    vector<int> hash;
    int ans=0,count=0;
    void help(TreeNode* root){
        hash[root->val]++; if(hash[root->val]%2) count++; else count--;
        if(root->left) help(root->left);
        if(root->right) help(root->right);
        if(root->left==root->right && count<=1) ans++;
        hash[root->val]--; if(hash[root->val]%2) count++; else count--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        hash.resize(10);
        help(root);
        return ans;
    }
};