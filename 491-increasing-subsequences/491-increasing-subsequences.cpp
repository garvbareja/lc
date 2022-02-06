class Solution {
public:
    vector<int> temp;
    set<vector<int>> st;
    void dfs(vector<int>& nums,int i){
        if(i==nums.size()){
            if(temp.size()>=2) st.insert(temp);
            return;
        }
        if(!temp.size() || temp.size() && temp.back()<=nums[i]){
            temp.push_back(nums[i]);
            dfs(nums,i+1);
            temp.pop_back();
        }
        dfs(nums,i+1);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums,0);
        return vector<vector<int>>(st.begin(),st.end());
    }
};