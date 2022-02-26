class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1) return 0;
        string allvisit(graph.size(),'1');
        queue<pair<int,string>> q;
        set<pair<int,string>> vis;
        for(int i=0;i<graph.size();i++){
            string temp(graph.size(),'0'); temp[i]='1';
            q.push({i,temp}); vis.insert({i,temp});
        }
        
        int step=0,v; string cur; char tempchr;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                v=q.front().first; cur=q.front().second; q.pop();
                for(int i=0;i<graph[v].size();i++){
                    tempchr=cur[graph[v][i]];
                    cur[graph[v][i]]='1';
                    if(cur==allvisit) return step+1;
                    if(!vis.count({graph[v][i],cur})){q.push({graph[v][i],cur}); vis.insert({graph[v][i],cur});}
                    cur[graph[v][i]]=tempchr;
                }
            }
            step++;
        }
        return -1;
    }
};