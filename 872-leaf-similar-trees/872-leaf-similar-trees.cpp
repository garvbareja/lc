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
    vector<int> leaf;
    void buildleaves(TreeNode* root){
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return;
        }
        if(root->left) buildleaves(root->left);
        if(root->right) buildleaves(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root) {
        buildleaves(root1);
        stack<TreeNode*> s; int index=0;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top(); s.pop();
            if(!root->left && !root->right){
                if(index==leaf.size()) return false;
                if(leaf[index++]!=root->val) return false;
            }
            root=root->right;
        }
        return index==leaf.size();
    }
};