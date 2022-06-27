class Solution {
public:
    int dfs(vector<int>& nums,int left,int right) {
        int prev=0,dprev=0,cur;
        for(int i=right;i>=left;i--){
            cur=max(nums[i]+dprev,prev);
            dprev=prev;
            prev=cur;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(dfs(nums,0,nums.size()-2),dfs(nums,1,nums.size()-1));
    }
};