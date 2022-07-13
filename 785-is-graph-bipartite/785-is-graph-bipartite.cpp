class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int v,int paint){
        color[v]=paint;
        for(int i=0;i<graph[v].size();i++){
            if(color[graph[v][i]]==-1){
                if(!dfs(graph,color,graph[v][i],paint^1)) return false;
            }else if(color[graph[v][i]]==paint) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(graph,color,i,0)) return false;
            } 
        }
        return true;
    }
};