class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev=0,prev2=0;
        for(int i=cost.size()-1;i>=0;i--){
            int curcost=cost[i]+min(prev,prev2);
            prev2=prev;
            prev=curcost;
        }
        return min(prev,prev2);
    }
};