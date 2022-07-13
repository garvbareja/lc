class Solution {
public:
    void dfs(unordered_set<int> neighbour[],unordered_set<int> edges[],vector<bool> &vis,int v,int &res){
        vis[v]=true;
        for(auto it=neighbour[v].begin();it!=neighbour[v].end();it++){
            if(!vis[*it]){
                vis[*it]=true;
                dfs(neighbour,edges,vis,*it,res);
                if(edges[v].count(*it)) res+=1;
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& c) {
        
        unordered_set<int> neighbour[n];
        unordered_set<int> edges[n];
        vector<bool> vis(n);
        
        for(int i=0;i<c.size();i++){
            neighbour[c[i][0]].insert(c[i][1]);
            neighbour[c[i][1]].insert(c[i][0]);
            edges[c[i][0]].insert(c[i][1]);
        }
        
        int res=0;
        dfs(neighbour,edges,vis,0,res);
        return res;
    }
};