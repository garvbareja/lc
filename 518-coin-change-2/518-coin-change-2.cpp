class Solution {
public:
    int change(int a, vector<int>& coins) {
        vector<int> cur(a+1); cur[0]=1;
        for(int n=1;n<=coins.size();n++)
            for(int amount=1;amount<=a;amount++)
                if(coins[n-1]<=amount) cur[amount]+=cur[amount-coins[n-1]];
        return cur[a];
    }
};