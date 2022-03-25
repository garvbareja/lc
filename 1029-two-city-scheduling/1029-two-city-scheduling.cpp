class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]-a[0]<b[1]-b[0];
    }
    
    int twoCitySchedCost(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),cmp); int res=0;
        for(int i=0;i<nums.size();i++){
            if(i>=nums.size()/2) res+=nums[i][0];
            else res+=nums[i][1];
        }
        return res;
    }
};