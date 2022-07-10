class Solution {
public:
    int bfs(vector<pair<int,int>> adj[],int v,int color,int n){
        queue<pair<int,int>> q; q.push({0,color^1});
        vector<vector<bool>> vis(n,vector<bool>(2)); vis[0][color]=true;
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int vertex=q.front().first; int nextcolor=q.front().second; q.pop();
                if(vertex==v) return dist;
                for(int i=0;i<adj[vertex].size();i++){
                    if(adj[vertex][i].second==nextcolor && !vis[adj[vertex][i].first][nextcolor]){
                        q.push({adj[vertex][i].first,nextcolor^1});
                        vis[adj[vertex][i].first][nextcolor]=true;
                    }
                }
            }
            dist++;
        }
        return 10000;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& rededges, vector<vector<int>>& blueedges) {
        vector<pair<int,int>> adj[n]; vector<int> res(n);
        for(int i=0;i<rededges.size();i++) adj[rededges[i][0]].push_back({rededges[i][1],0});
        for(int i=0;i<blueedges.size();i++) adj[blueedges[i][0]].push_back({blueedges[i][1],1});
        
        for(int i=0;i<n;i++){
            int ans=min(bfs(adj,i,0,n),bfs(adj,i,1,n));
            if(ans==10000) res[i]=-1;
            else res[i]=ans;
        }
        return res;
    }
};