class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> prev(2*k+1,0),cur(2*k+1,0);
        for(int index=prices.size()-1;index>=0;index--){
            for(int transno=2*k-1;transno>=0;transno--){
                if(!(transno%2)) cur[transno]=max(prev[transno],-prices[index]+prev[transno+1]);
                else cur[transno]=max(prev[transno],prices[index]+prev[transno+1]);
            }
            prev=cur;
        }
        return prev[0];
    }
};