class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int v,int col){
        color[v]=col;
        for(int i=0;i<graph[v].size();i++){
            if(color[graph[v][i]]==-1){
                if(!dfs(graph,color,graph[v][i],col^1)) return false;
            }else{
                if(color[graph[v][i]]==col) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1)
                if(!dfs(graph,color,i,1)) return false;
        }
        return true;
    }
};