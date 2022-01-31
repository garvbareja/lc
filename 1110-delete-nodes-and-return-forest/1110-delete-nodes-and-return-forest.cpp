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
    unordered_set<int> hash;
    void dfs(TreeNode* cur,TreeNode* parent){
        if(!cur) return;
        dfs(cur->left,cur);
        dfs(cur->right,cur);
        if(hash.count(cur->val)){
            if(parent){
                if(parent->left && parent->left->val==cur->val) parent->left=nullptr;
                else parent->right=nullptr;
            }
            if(cur->left) ans.push_back(cur->left);
            if(cur->right) ans.push_back(cur->right);
        }else{
            if(!parent) ans.push_back(cur);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0;i<to_delete.size();i++) hash.insert(to_delete[i]);
        dfs(root,nullptr);
        return ans;
    }
};