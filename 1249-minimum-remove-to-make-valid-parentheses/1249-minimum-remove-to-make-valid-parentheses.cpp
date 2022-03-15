class Solution {
public:
    string minRemoveToMakeValid(string &s) {
        stack<pair<char,int>> stk;
        for(int i=0;i<s.length();i++){
            cout<<s[i];
            if(s[i]=='(') stk.push({s[i],i});
            if(s[i]==')'){
                if(!stk.empty() && stk.top().first=='(') stk.pop();
                else stk.push({s[i],i});
            }
        }
        string res="";
        for(int i=s.length()-1;i>=0;i--){
            if(!stk.empty() && stk.top().second==i) stk.pop();
            else res.push_back(s[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};