class Solution {
public:
    void dfs(vector<int> adj[],int v,vector<bool>& vis){
        vis[v]=true;
        for(int i=0;i<adj[v].size();i++) if(!vis[adj[v][i]]) dfs(adj,adj[v][i],vis);
    }
    
    int makeConnected(int n, vector<vector<int>>& nums) {
        if(nums.size()<n-1) return -1;
        vector<int> adj[n]; vector<bool> vis(n); int res=0;
        for(int i=0;i<nums.size();i++){
            adj[nums[i][0]].push_back(nums[i][1]);
            adj[nums[i][1]].push_back(nums[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                res+=1;
            }
        }
        return res-1;
    }
};