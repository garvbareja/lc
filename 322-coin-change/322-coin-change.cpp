class Solution {
public:

    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cur(amount+1);
        for(int j=0;j<=amount;j++){
            if(j%coins[0]) cur[j]=INT_MAX-1;
            else cur[j]=j/coins[0];
        }
        for(int i=2;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(coins[i-1]<=j) cur[j]=min(cur[j],1+cur[j-coins[i-1]]);
            }
        }
        if(cur[amount]==INT_MAX-1) return -1;
        else return cur[amount];
    }
};