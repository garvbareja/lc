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
    int k;
    long findsecondmin(TreeNode* root){
        if(!root) return LONG_MAX;
        if(root->val==k) return min(findsecondmin(root->left),findsecondmin(root->right));
        return root->val;
    }
    int findSecondMinimumValue(TreeNode* root) {
        k=root->val;
        long res=findsecondmin(root);
        return res==LONG_MAX?-1:res;
    }
};