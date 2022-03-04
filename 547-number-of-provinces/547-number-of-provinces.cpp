class Solution {
public:
    vector<bool> vis;
    void dfs(vector<vector<int>>& g,int v){
        vis[v-1]=true;
        for(int i=0;i<g[v-1].size();i++) if(!vis[i] && g[v-1][i]) dfs(g,i+1);
    }
    
    int findCircleNum(vector<vector<int>>& g) {
        int province=0;
        vis.resize(g.size());
        for(int i=1;i<=g.size();i++){
            if(!vis[i-1]){
                province++;
                dfs(g,i);
            }
        }
        return province;
    }
};