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
    class data{
    public:
        int num;
        int sum;
        data(){
            num=0;
            sum=0;
        }
    };
    
    int ans=0;
    data dfs(TreeNode* root){
        if(!root) return *(new data());
        data left=dfs(root->left);
        data right=dfs(root->right);
        data res;
        res.sum=left.sum+right.sum+root->val;
        res.num=left.num+right.num+1;
        if((res.sum/res.num)==root->val) ans+=1;
        return res;
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};