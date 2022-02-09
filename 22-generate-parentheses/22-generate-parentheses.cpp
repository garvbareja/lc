class Solution {
public:
    string temp="";
    vector<string> ans;
    void dfs(int n,int open,int closed){
        if(open==n && closed==n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            temp.push_back('(');
            dfs(n,open+1,closed);
            temp.pop_back();
        }
        if(closed<open){
            temp.push_back(')');
            dfs(n,open,closed+1);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0);
        return ans;
    }
};