class Solution {
public:
    int help(string& s,int k,char cur){
        int i=0,j=0,ans=0;
        while(i<s.length()){
            if(s[i]!=cur){
                if(k) k--;
                else{
                    while(s[j]==cur) j++;
                    j++;
                }
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
    
    int characterReplacement(string &s, int k){
        vector<bool> present(26); int ans=0;
        for(int i=0;i<s.length();i++) present[s[i]-'A']=true;
        for(int i=0;i<26;i++) if(present[i]) ans=max(ans,help(s,k,i+'A'));
        return ans;
    }
};