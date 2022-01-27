class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> ans;
    void dfs(vector<int>&nums,vector<int>& temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=true;
                temp.push_back(nums[i]);
                dfs(nums,temp);
                vis[i]=false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size());
        vector<int> temp;
        dfs(nums,temp);
        return ans;
    }
};