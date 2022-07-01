class Solution {
public:
    static bool custom(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& nums, int cap) {
        sort(nums.begin(),nums.end(),custom); int res=0,i=0; 
        while(i<nums.size() && cap){
            int sub=min(cap,nums[i][0]);
            res+=sub*nums[i][1];
            cap-=sub;
            i++;
        }
        return res;
    }
};