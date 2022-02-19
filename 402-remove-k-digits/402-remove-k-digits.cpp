class Solution {
public:
    string removeKdigits(string &s, int k) {
        if(k==s.length()) return "0";
        string ans="";
        for(int i=0;i<s.length();i++){
            if(ans.length()){
                while(k && ans.length() && ans.back()>s[i]){ans.pop_back(); k--;}
                if(ans.length() || s[i]!='0') ans.push_back(s[i]);
            }else{
                if(s[i]!='0') ans.push_back(s[i]);
            }
        }
        while(ans.length() && k) {ans.pop_back(); k--;}
        return ans.length()?ans:"0";
    }
};