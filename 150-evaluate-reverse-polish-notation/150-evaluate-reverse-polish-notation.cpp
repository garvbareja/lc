class Solution {
public:
    bool digit(string& s){
        if(s.length()==1 && !isdigit(s[0])) return false;
        return true;
    }
    
    int todigit(string& s){
        int ret=0;
        bool flag=false;
        int i=0;
        if(s[i]=='-'){
            flag=true;
            i++;
        }
        for(;i<s.length();i++){
            ret*=10;
            ret+=(s[i]-'0');
        }
        if(flag) return -ret;
        return ret;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int i=0;
        while(i<tokens.size()){
            if(digit(tokens[i])){
                s.push(todigit(tokens[i]));
            }else{
                int x=s.top(); s.pop();
                int y=s.top(); s.pop();
                if(tokens[i]=="+"){
                    y+=x;
                }else if(tokens[i]=="-"){
                    y-=x;
                }else if(tokens[i]=="*"){
                    y*=x;
                }else{
                    y/=x;
                }
                s.push(y);
            }
            i++;
        }
        return s.top();
    }
};