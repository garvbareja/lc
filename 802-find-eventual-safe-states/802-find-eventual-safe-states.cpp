class Solution {
public:
    vector<int> ans;
    bool help(int v,vector<bool>& vis,vector<bool>& dfsvis,vector<bool>& safe,vector<vector<int>>& graph){
        vis[v]=true; dfsvis[v]=true;
        bool flag = true;
        for(int i=0;i<graph[v].size();i++){
            if(!vis[graph[v][i]]){
                if(!(help(graph[v][i],vis,dfsvis,safe,graph))){
                    flag = false;
                    break;
                }
            }else{
                if(dfsvis[graph[v][i]]){
                    flag = false;
                    break;
                }else{
                    if(!safe[graph[v][i]]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag){
            safe[v]=true;
            ans.push_back(v);
        }else{
            safe[v]=false;
        }
        dfsvis[v]=false;
        return flag;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size());
        vector<bool> dfsvis(graph.size());
        vector<bool> safe(graph.size());
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                help(i,vis,dfsvis,safe,graph);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};