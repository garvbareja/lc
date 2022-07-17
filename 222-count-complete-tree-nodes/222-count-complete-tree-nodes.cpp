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
    int calclh(TreeNode* root){
        int lh=0;
        while(root){
            root=root->left;
            lh++;
        }
        return lh;
    }
    
    int calcrh(TreeNode* root){
        int rh=0;
        while(root){
            root=root->right;
            rh++;
        }
        return rh;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=calclh(root->left);
        int rh=calcrh(root->right);
        if(lh!=rh) return 1+countNodes(root->left)+countNodes(root->right);
        else return pow(2,lh+1)-1;
    }
};