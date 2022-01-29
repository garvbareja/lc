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
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int sum){
        if(!root) return;
        if(!root->left && !root->right && root->val==sum){
            temp.push_back(sum);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};