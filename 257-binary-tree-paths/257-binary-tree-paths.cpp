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
    vector<string> ans;
    string temp="";
    void dfs(TreeNode* root){
        if(!root->left && !root->right){
            temp+=to_string(root->val);
            ans.push_back(temp);
            int ok =root->val;
            while(ok){
                temp.pop_back();
                ok/=10;
            }
            if(root->val<0) temp.pop_back();
        }
        temp+=to_string(root->val)+"->";
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        temp.pop_back(); temp.pop_back();
        int ok=root->val;
        while(ok){
                temp.pop_back();
                ok/=10;
        }
        if(root->val<0) temp.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root){
        dfs(root);
        return ans;
    }
};