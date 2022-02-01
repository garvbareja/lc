class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<pair<int,int>> count;
    
    int help(vector<string>& s,int zero,int one,int i){
        if(i==s.size()) return 0;
        if(dp[i][zero][one]!=-1) return dp[i][zero][one];
        pair<int,int> freq = count[i];
        if(freq.first<=zero && freq.second<=one)
            return dp[i][zero][one]=max(1+help(s,zero-freq.first,one-freq.second,i+1),help(s,zero,one,i+1));
        else return dp[i][zero][one]= help(s,zero,one,i+1);
    }
    
    int findMaxForm(vector<string>& s, int m, int n){
        dp.resize(s.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        count.resize(s.size());
        for(int i=0;i<s.size();i++){
            int zero=0,one=0;
            for(int j=0;j<s[i].length();j++){
                if(s[i][j]=='1') one++;
                else zero++;
            }
            count[i]={zero,one};
        }
        return help(s,m,n,0);
    }
};