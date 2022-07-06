class Solution {
public:
    int longestCommonSubsequence(string s, string p) {
        vector<int> prev(p.length()+1); vector<int> cur(p.length()+1);
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=p.length();j++){
                if(s[i-1]==p[j-1]) cur[j]=1+prev[j-1];
                cur[j]=max(cur[j],max(prev[j],cur[j-1]));
            }
            prev=cur;
        }
        return prev[p.length()];
    }
};