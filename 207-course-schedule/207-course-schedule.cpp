class Solution {
public:
    bool check_cycle(vector<int> adj[],int v,vector<bool>& vis,vector<bool>& cycle){
        vis[v]=true; cycle[v]=true;
        for(int i=0;i<adj[v].size();i++){
            if(!vis[adj[v][i]]){
                if(check_cycle(adj,adj[v][i],vis,cycle)) return true;
            }else if(cycle[adj[v][i]]) return true;
        }
        cycle[v]=false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n]; vector<bool> cycle(n),vis(n);
        for(int i=0;i<prerequisites.size();i++) adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for(int v=0;v<n;v++) if(!vis[v]) if(check_cycle(adj,v,vis,cycle)) return false;
        return true;
    }
};