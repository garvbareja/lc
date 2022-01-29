class Solution {
public:
    unordered_map<int,int> hash;
    int ans=0;
    void dfs(TreeNode* root,int& sum,int runningsum){
        if(!root) return;
        runningsum+=root->val;
        if(hash.count(runningsum-sum)) ans+=hash[runningsum-sum];
        hash[runningsum]++;
        dfs(root->left,sum,runningsum);
        dfs(root->right,sum,runningsum);
        hash[runningsum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        hash[0]=1;
        dfs(root,targetSum,0);
        return ans;
    }
};