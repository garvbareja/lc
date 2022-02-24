class Solution {
public:
    vector<bool> vis;
    void dfs(vector<vector<int>>& graph,int v){
        vis[v]=true;
        for(int i=0;i<graph[v].size();i++) if(graph[v][i] && !vis[i]) dfs(graph,i);
    }
    
    int findCircleNum(vector<vector<int>>& graph){
        vis.resize(graph.size()); int ans=0;
        for(int v=0;v<graph.size();v++){
            if(!vis[v]){
                dfs(graph,v);
                ans++;
            }
        }
        return ans;
    }
};