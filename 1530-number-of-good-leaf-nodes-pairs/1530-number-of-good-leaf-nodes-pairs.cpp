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
    int dist,ans=0;
    vector<int> dfs(TreeNode* root){
        if(!root->left && !root->right){
            vector<int> temp(dist+1);
            temp[1]=1;
            return temp;
        }
        vector<int> left(dist+1),right(dist+1);
        if(root->left) left=dfs(root->left);
        if(root->right) right=dfs(root->right);
        if(root->left && root->right)
        for(int i=1;i<=dist;i++){
            for(int j=1;i+j<=dist;j++){
                ans+=left[i]*right[j];
            }
        }
        
        for(int i=dist-1;i>=0;i--) right[i+1]=right[i]+left[i];
        return right;
    }
    
    int countPairs(TreeNode* root, int distance){
        dist=distance;
        dfs(root);
        return ans;
    }
};