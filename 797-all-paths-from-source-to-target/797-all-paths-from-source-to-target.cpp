class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph,int v){
        temp.push_back(v);
        if(v==graph.size()-1){ans.push_back(temp); temp.pop_back(); return;}
        for(int i=0;i<graph[v].size();i++) dfs(graph,graph[v][i]);
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph,0);
        return ans;
    }
};