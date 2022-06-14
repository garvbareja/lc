class Solution {
public:
    static bool custom(vector<int>&a, vector<int>& b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),custom);
        vector<vector<int>> res; res.push_back(nums[0]); int i=1;
        while(i<nums.size()){
            if(nums[i][0]<=res.back()[1]) res.back()[1]=max(res.back()[1],nums[i][1]);
            else res.push_back(nums[i]);
            i++;
        }
        return res;
    }
};