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
    vector<TreeNode*> ans;
    unordered_map<string,bool> hash;
    string help(TreeNode* root){
        if(!root) return "";
        string res ="";
        res+=to_string(root->val)+",";
        res+=help(root->left)+",";
        res+=help(root->right);
        if(hash.count(res)){
            if(!hash[res]){
                ans.push_back(root);
                hash[res]=true;
            }
        }else{
            hash[res]=false;
        }
         return res;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        help(root);
        return ans;
    }
};