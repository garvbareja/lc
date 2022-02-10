class Solution {
public:
    int longestValidParentheses(string &s){
        int open=0,ans=0;
        int j=0;
        //l-->> r
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') open++;
            else open--;
            if(!open) ans=max(ans,i-j+1);
            if(open<0){
                open=0;
                j=i+1;
            }
        }
        //l <<-- r
        open=0,j=s.length()-1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')') open++;
            else open--;
            if(!open) ans=max(ans,j-i+1);
            if(open<0){
                j=i-1;
                open=0;
            }
        }
        return ans;
    }
};