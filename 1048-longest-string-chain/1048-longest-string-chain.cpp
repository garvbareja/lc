class Solution {
public:
    static bool custom(string& a,string& b){
        if(a.length()==b.length()) return a<b;
        return a.length()<b.length();
    }
    
    bool valid(string a,string b){
        if(b.length()!=a.length()+1) return false;
        bool flag=true; int i=0; int j=0;
        while(i<a.length() && j<b.length()){
            if(a[i]!=b[j]){
                if(flag){
                    j++;
                    flag=false;
                }else return false;
            }else{
                i++; j++;
            }
        }
        if(flag) j++;
        return j==b.length();
    }
    
    int longestStrChain(vector<string>& words) {
        if(words.size()==1) return 1; sort(words.begin(),words.end(),custom); int res=1;
        vector<int> dp(words.size(),1);
        for(int i=1;i<words.size();i++){
            for(int pi=i-1;pi>=0;pi--){
                if(dp[i]<1+dp[pi] && valid(words[pi],words[i])){
                    dp[i]=1+dp[pi];
                }
                res=max(res,dp[i]);
            }
        }
        return res;
    }
};