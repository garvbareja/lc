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
    vector<vector<int>> ans;
    vector<int> temp;
    void help(TreeNode* root,int target){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && target==root->val){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(root->left) help(root->left,target-root->val);
        if(root->right) help(root->right,target-root->val);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return {};
        help(root,target);
        return ans;
    }
};