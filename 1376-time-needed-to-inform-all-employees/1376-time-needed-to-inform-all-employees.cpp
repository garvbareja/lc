class Solution {
public:
    int dfs(vector<int> adj[],vector<int> &informtime,int headid){
        int time=0;
        for(int i=0;i<adj[headid].size();i++){
            time=max(time,informtime[headid]+dfs(adj,informtime,adj[headid][i]));
        }
        return time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[manager.size()];
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(adj,informTime,headID);
    }
};