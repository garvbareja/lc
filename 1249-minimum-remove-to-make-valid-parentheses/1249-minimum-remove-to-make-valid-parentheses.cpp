class Solution {
public:
    string minRemoveToMakeValid(string &s) {
        int open=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') open++;
            if(s[i]==')'){
                if(open) open--;
                else s[i]='$';
            }
        }
        open=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')') open++;
            if(s[i]=='('){
                if(open) open--;
                else s[i]='$';
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='$') ans.push_back(s[i]);
        }
        return ans;
    }
};