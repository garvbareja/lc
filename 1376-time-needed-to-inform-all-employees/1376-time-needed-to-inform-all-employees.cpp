class Solution {
public:
    int dfs(vector<int> adj[],vector<int>& informtime,int headid){
        if(adj[headid].size()==0) return 0;
        int res=0;
        for(int i=0;i<adj[headid].size();i++){
            res=max(res,dfs(adj,informtime,adj[headid][i]));
        }
        return res+informtime[headid];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<manager.size();i++){
            if(i!=headID) adj[manager[i]].push_back(i);
        }
        return dfs(adj,informTime,headID);
    }
};