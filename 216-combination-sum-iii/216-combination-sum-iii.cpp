class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans; int len;
    void dfs(int sum,int i){
        if(sum<0) return;
        if(temp.size()==len){
            if(!sum) ans.push_back(temp);
            return;
        }
        if(i>=10) return;
        temp.push_back(i); dfs(sum-i,i+1); temp.pop_back();
        dfs(sum,i+1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n){
        len=k;
        dfs(n,1);
        return ans;
    }
};