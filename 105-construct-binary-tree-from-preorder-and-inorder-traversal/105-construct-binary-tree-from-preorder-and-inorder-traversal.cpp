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
    TreeNode* build(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int>& hash){
        if(is>ie || ps>pe) return nullptr;
        int rootindex=hash[preorder[ps]];
        TreeNode* root=new TreeNode(inorder[rootindex]);
        int leftelements=rootindex-is;
        root->left=build(preorder,ps+1,ps+leftelements,inorder,is,rootindex-1,hash);
        root->right=build(preorder,ps+leftelements+1,pe,inorder,rootindex+1,ie,hash);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hash;
        for(int i=0;i<inorder.size();i++) hash[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hash);
    }
};