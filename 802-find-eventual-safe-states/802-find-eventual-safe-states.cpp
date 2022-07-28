class Solution {
public:
    unordered_set<int> res;
    bool cycle(vector<vector<int>>& graph,vector<bool> &vis,vector<bool> &dfsvis,int v){
        vis[v]=true; dfsvis[v]=true; bool flag=false;
        for(int i=0;i<graph[v].size();i++){
            if(!vis[graph[v][i]] && !dfsvis[graph[v][i]]){
                if(cycle(graph,vis,dfsvis,graph[v][i])) flag=true;
            }else{
                if(dfsvis[graph[v][i]]) flag=true;
                else{
                    if(!res.count(graph[v][i])) flag=true;
                }
            }
        }
        dfsvis[v]=false;
        if(!flag) res.insert(v);
        return flag;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size()),dfsvis(graph.size());
        for(int i=0;i<graph.size();i++){
            if(!vis[i]) cycle(graph,vis,dfsvis,i);
        }
        vector<int> ans(res.begin(),res.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};