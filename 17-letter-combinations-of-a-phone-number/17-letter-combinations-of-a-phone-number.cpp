class Solution {
public:
    vector<string> ans;
    void dfs(string &digits,int i,vector<string>& hash,string& temp){
        if(i==digits.length()) {ans.push_back(temp); return;}
        for(int z=0;z<hash[digits[i]-'2'].length();z++){
            temp.push_back(hash[digits[i]-'2'][z]);
            dfs(digits,i+1,hash,temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string &digits){
        if(digits.length()==0) return {};
        vector<string> hash={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp="";
        dfs(digits,0,hash,temp);
        return ans;
    }
};