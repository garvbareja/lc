class Solution {
public:
    void eval(string& s,int &i,int &cur){
        cur=0;
        while(i<s.length() && isdigit(s[i])){
            cur=cur*10 + (s[i]-'0');
            i+=1;
        }
    }
    
    void removeSpace(string& s,int &i){
        while(i<s.length() && s[i]==' ') i+=1;
    }
    
    int calculate(string &s) {
        stack<int> stack; int i=0,cur=0; char sign;
        removeSpace(s,i);
        eval(s,i,cur); 
        stack.push(cur);
        removeSpace(s,i);
        sign=s[i]; i+=1;
        while(i<s.length()){
            removeSpace(s,i);
            eval(s,i,cur);
            removeSpace(s,i);
            if(sign=='+') stack.push(cur);
            else if(sign=='-') stack.push(-cur);
            else if(sign=='*') stack.top()*=cur;
            else stack.top()/=cur;
            if(i<s.length()) sign=s[i];
            i+=1;
        }
        cur=0;
        while(stack.size()){
            cur+=stack.top(); stack.pop();
        }
        return cur;
    }
};