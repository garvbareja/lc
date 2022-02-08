class Solution {
public:
    vector<int> temp;
    set<vector<int>> st;
    void dfs(vector<int>& nums,int i){
        if(i==nums.size()) return;
            temp.push_back(nums[i]); st.insert(temp); dfs(nums,i+1); temp.pop_back();
            dfs(nums,i+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        vector<vector<int>> ans(st.begin(),st.end());
        ans.push_back({});
        return ans;
    }
};