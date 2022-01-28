class Solution {
public:
    vector<string> ans;
    void dfs(string& s,int i,string& cur){
        if(i==s.length()){
            ans.push_back(cur);
            return;
        }
        if(isdigit(s[i])){
            cur+=s[i];
            dfs(s,i+1,cur);
        }
        else{
            cur+=toupper(s[i]);
            dfs(s,i+1,cur); cur.pop_back();
            cur+=tolower(s[i]);
            dfs(s,i+1,cur);
        }
        cur.pop_back();
    }
    
    vector<string> letterCasePermutation(string s) {
        string cur="";
        dfs(s,0,cur);
        return ans;
    }
};