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
    vector<TreeNode*> help(int lo,int hi){
        if(lo>hi) return {nullptr};
        if(lo==hi) return {new TreeNode(lo)};
        vector<TreeNode*> res;
        for(int z=lo;z<=hi;z++){
            vector<TreeNode*> lft = help(lo,z-1);
            vector<TreeNode*> rght = help(z+1,hi);
            for(int i=0;i<lft.size();i++){
                for(int j=0;j<rght.size();j++){
                    TreeNode* root = new TreeNode(z);
                    root->left = lft[i];
                    root->right = rght[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return help(1,n);
    }
};