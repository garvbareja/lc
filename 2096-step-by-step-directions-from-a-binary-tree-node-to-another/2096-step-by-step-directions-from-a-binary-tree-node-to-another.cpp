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
    TreeNode* ans=nullptr;
    bool dfs(TreeNode* root,int p,int q){
        if(!root) return false;
        bool flag1=false;
        bool flag2=false;
        flag1=dfs(root->left,p,q);
        flag2=dfs(root->right,p,q);
        if((root->val==p||root->val==q)&&(flag1||flag2)&&!ans) ans=root;
        if(flag1 && flag2 && !ans) ans=root;
        return root->val==p||root->val==q||flag1||flag2;
    }
    
    int findpath(TreeNode* start,int end){
        if(!start) return INT_MAX/100;
        if(start->val==end) return 0;
        return 1+min(findpath(start->left,end),findpath(start->right,end));
    }
    
    bool completepath(TreeNode* start,int end,string& res){
        if(!start) return false;
        if(start->val==end) return true;
        res.push_back('L');
        if(completepath(start->left,end,res)) return true;
        res.pop_back(); res.push_back('R');
        if(completepath(start->right,end,res)) return true;
        res.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int start, int end) {       
        dfs(root,start,end);
        TreeNode* flag= ans;
        int downs=findpath(flag,start);
        string res(downs,'U');
        completepath(flag,end,res);
        return res;
    }
};