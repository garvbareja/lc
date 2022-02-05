class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int>& nums,int sum,int i){
        if(sum<0) return;
        if(!sum){ans.push_back(temp); return;}
        if(i==nums.size()) return;
        temp.push_back(nums[i]); dfs(nums,sum-nums[i],i); temp.pop_back();
        dfs(nums,sum,i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int sum) {
        dfs(nums,sum,0);
        return ans;
    }
};