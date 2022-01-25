class Solution {
public:
    
    vector<vector<vector<int>>> dp;
    
    int helper(vector<int>& prices,int i,int flag,int k)
    {
        if(i==prices.size() || k==2) return 0;
        
        if(dp[i][flag][k]!=-1) return dp[i][flag][k];
        
        int one=0;
        int two=0;
        if(flag==0){
            one=helper(prices,i+1,1,k)-prices[i];
            two=helper(prices,i+1,0,k);
        }
        else if(flag==1){
            one=helper(prices,i+1,0,k+1)+prices[i];
            two=helper(prices,i+1,1,k);
        }
        
        return dp[i][flag][k]= max(one,two);
    }
    
    int maxProfit(vector<int>& prices) {
    
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(prices,0,0,0);
    }
};