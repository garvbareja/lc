class Solution {
public:
    string removeKdigits(string &num, int k) {
        if(k==num.length()) return "0";
        string ans="";
        for(int i=0;i<num.length();i++){
            if(ans.length()){
                while(k && ans.back()>num[i]){
                    ans.pop_back(); k--;
                }
                if(ans.length() || num[i]!='0') ans.push_back(num[i]);
            }else if(num[i]!='0') ans.push_back(num[i]);
        }
        while(k-- && ans.length()) ans.pop_back();
        return ans.length()?ans:"0";
    }
};