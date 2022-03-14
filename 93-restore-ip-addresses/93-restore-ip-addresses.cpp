class Solution {
public:
    string temp="";
    vector<string> ans;
    void dfs(string &s,int i,int dot){
        if(i==s.length()){
            if(dot==4){
                temp.pop_back();
                ans.push_back(temp);
                temp.push_back('.');
            }
            return;
        }
        if(dot==4) return;
        if(s[i]=='0'){
            temp.push_back('0'); temp.push_back('.'); dfs(s,i+1,dot+1); temp.pop_back(); temp.pop_back();
            return;
        }
        if(s[i]=='1'){
            temp.push_back('1'); temp.push_back('.'); dfs(s,i+1,dot+1); temp.pop_back(); temp.pop_back();
            if(i+1<s.length()){
                temp.push_back('1'); temp.push_back(s[i+1]); temp.push_back('.'); dfs(s,i+2,dot+1); temp.pop_back();temp.pop_back();temp.pop_back();
            }
            if(i+2<s.length()){
                temp.push_back('1'); temp.push_back(s[i+1]); temp.push_back(s[i+2]); temp.push_back('.'); dfs(s,i+3,dot+1);
                temp.pop_back(); temp.pop_back(); temp.pop_back(); temp.pop_back();
            }
            return;
        }
        if(s[i]=='2'){
            temp.push_back('2'); temp.push_back('.'); dfs(s,i+1,dot+1); temp.pop_back(); temp.pop_back();
            if(i+1<s.length()){
                temp.push_back('2'); temp.push_back(s[i+1]); temp.push_back('.'); dfs(s,i+2,dot+1); temp.pop_back();temp.pop_back();temp.pop_back();
            }
            if(i+2<s.length() && s[i+1]<='5'){
                if(s[i+1]=='5' && s[i+2]<='5' || s[i+1]<='4'){
                    temp.push_back('2'); temp.push_back(s[i+1]); temp.push_back(s[i+2]); temp.push_back('.'); dfs(s,i+3,dot+1);
                temp.pop_back(); temp.pop_back(); temp.pop_back(); temp.pop_back();
                }
            }
            return;
        }
        temp.push_back(s[i]); temp.push_back('.'); dfs(s,i+1,dot+1); temp.pop_back(); temp.pop_back();
        if(i+1<s.length()){
            temp.push_back(s[i]); temp.push_back(s[i+1]); temp.push_back('.'); dfs(s,i+2,dot+1); temp.pop_back();temp.pop_back();temp.pop_back();
        }
    }
    
    vector<string> restoreIpAddresses(string &s) {
        dfs(s,0,0);
        return ans;
    }
};