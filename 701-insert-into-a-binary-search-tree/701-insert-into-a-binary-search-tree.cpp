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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* res=root;
        TreeNode* newnode = new TreeNode(val);
        if(!root) return newnode;
        while(root){
            if(root->val<val){
                if(root->right){
                    root=root->right;
                }else{
                    root->right=newnode;
                    break;
                }
            }else{
                if(root->left){
                    root=root->left;
                }else{
                    root->left=newnode;
                    break;
                }
            }
        }
        return res;
    }
};