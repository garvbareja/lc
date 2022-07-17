class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> hash; bool flag=false; int maxi=routes[0][0];
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                hash[routes[i][j]].push_back(i);
                if(routes[i][j]==source) flag=true;
                maxi=max(maxi,routes[i][j]);
            }
        }
        if(!flag) return -1;
        // vector<bool> vis(maxi+1);
        queue<int> q; q.push(source);
        // vis[source]=true;
        int bus_count=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int cur=q.front(); q.pop();
                if(cur==target) return bus_count;
                for(int i=0;i<hash[cur].size();i++){
                    for(int j=0;j<routes[hash[cur][i]].size();j++){
                        // if(routes[hash[cur][i]][j]!=cur && !vis[routes[hash[cur][i]][j]]){
                        if(routes[hash[cur][i]][j]!=cur){
                            // vis[routes[hash[cur][i]][j]]=true;
                            q.push(routes[hash[cur][i]][j]);
                        }
                    }
                    routes[hash[cur][i]].clear();
                }
            }
            bus_count+=1;
        }
        return -1;
    }
};