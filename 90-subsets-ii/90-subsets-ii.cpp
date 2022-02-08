class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int>& nums,int i){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(j==i || nums[j-1]!=nums[j]){
                temp.push_back(nums[j]);
                dfs(nums,j+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }
};