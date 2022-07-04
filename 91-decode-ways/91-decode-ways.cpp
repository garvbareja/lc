class Solution {
public:
    int numDecodings(string s) {
        int prev=1,dprev=1,cur;
        for(int i=s.length()-1;i>=0;i--){
            cur=0;
            if(s[i]=='1' && i+1<s.length()) cur+=dprev;
            if(s[i]=='2' && i+1<s.length() && s[i+1]<='6') cur+=dprev;
            cur+=prev;
            if(s[i]=='0') cur=0;
            dprev=prev;
            prev=cur;
        }
        return prev;
    }
};