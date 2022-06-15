class Solution {
public:
    static bool custom(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),custom);
        int end=nums[0][1]; int res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i][0]<end){
                res++;
                end=min(end,nums[i][1]);
            }
            else end=nums[i][1];
        }
        return res;
    }
};