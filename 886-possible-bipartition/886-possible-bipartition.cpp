class Solution {
public:
    bool dfs(vector<int> adj[],vector<int>& color,int v,int col){
        color[v]=col;
        for(int i=0;i<adj[v].size();i++){
            if(color[adj[v][i]]==-1){
                if(!dfs(adj,color,adj[v][i],col^1)) return false;
            }else{
                if(color[adj[v][i]]==col) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1]; vector<int> color(n+1,-1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!dfs(adj,color,i,0)) return false;
            }
        }
        return true;
    }
};