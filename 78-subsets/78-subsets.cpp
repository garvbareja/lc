class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,int i){
        if(i==nums.size()) return;
        temp.push_back(nums[i]); dfs(nums,i+1); ans.push_back(temp); temp.pop_back();
        dfs(nums,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums){
        dfs(nums,0);
        ans.push_back({});
        return ans;
    }
};