class Solution {
public:
    int dfs(vector<int>& nums,int left,int right){
        int prev=0,prev2=0;
        for(int i=right;i>=left;i--){
            int cur=max(prev,nums[i]+prev2);
            prev2=prev;
            prev=cur;
        }
        return max(prev,prev2);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        else return max(dfs(nums,0,nums.size()-2),dfs(nums,1,nums.size()-1));
    }
};