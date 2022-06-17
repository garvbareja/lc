class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<int> cur(amount+1); cur[0]=1;
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j) cur[j]+=cur[j-coins[i-1]];
            }
        }
        return cur[amount];
    }
};