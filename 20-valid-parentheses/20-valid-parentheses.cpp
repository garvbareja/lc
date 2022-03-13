class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2) return false;
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') stk.push(s[i]);
            else{
                if(stk.empty()) return false;
                if(s[i]==')'){if(stk.top()!='(') return false; stk.pop();}
                if(s[i]=='}'){if(stk.top()!='{') return false; stk.pop();}
                if(s[i]==']'){if(stk.top()!='[') return false; stk.pop();}
            }
        }
        return stk.empty();
    }
};