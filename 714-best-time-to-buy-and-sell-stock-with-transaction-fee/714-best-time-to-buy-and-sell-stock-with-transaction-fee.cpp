class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        vector<int> after(2); vector<int> cur(2);
        for(int index=nums.size()-1;index>=0;index--){
            cur[1]=max(after[1],-nums[index]+after[0]);
            cur[0]=max(after[0],nums[index]-fee+after[1]);
            after=cur;
        }
        return after[1];    
    }
};