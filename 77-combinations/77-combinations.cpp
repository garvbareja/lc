class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> vis;
    
    void dfs(int i,int n,int k){
        if(!k){
            ans.push_back(temp);
            return;
        }
        for(;i<=n;i++){
            if(!vis[i]){
            temp.push_back(i);
            vis[i]=true;
            dfs(i+1,n,k-1);
            temp.pop_back();
            vis[i]=false;
        }}
    }
    
    vector<vector<int>> combine(int n, int k){
        vis.resize(n+1);
        for(int i=1;i<=n;i++){
            temp.push_back(i);
            vis[i]=true;
            dfs(i+1,n,k-1);
            temp.pop_back();
        }
        return ans;
    }
};