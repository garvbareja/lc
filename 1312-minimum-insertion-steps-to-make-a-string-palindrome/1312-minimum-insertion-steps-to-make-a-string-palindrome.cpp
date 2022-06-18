class Solution {
public:
    int lcs(string s, string t){
        vector<int> cur(t.length()+1); vector<int> prev(t.length()+1);
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s[i-1]==t[j-1]) cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return cur[t.length()];
    }

    int minInsertions(string str) {
        string temp=str;
        reverse(temp.begin(),temp.end());
        int palin=lcs(str,temp);
        return str.length()-palin;
    }
};