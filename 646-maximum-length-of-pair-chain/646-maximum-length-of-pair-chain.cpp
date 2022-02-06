class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        vector<int> dp(pairs.size());
        int mxlen=1;
        for(int i=pairs.size()-1;i>=0;i--){
            int ans=1;
            for(int j=i+1;j<pairs.size();j++){
                if(pairs[i][1]<pairs[j][0]) ans=max(ans,1+dp[j]);
            }
            dp[i]=ans;
            mxlen=max(mxlen,dp[i]);
        }
        return mxlen;
    }
};