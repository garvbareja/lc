class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int prevbuy=0,prevsell=0,dprevbuy=0,curbuy,cursell;
        for(int i=nums.size()-1;i>=0;i--){
            curbuy=max(prevbuy,-nums[i]+prevsell);
            cursell=max(prevsell,nums[i]+dprevbuy);
            dprevbuy=prevbuy;
            prevbuy=curbuy;
            prevsell=cursell;
        }
        return prevbuy;
    }
};