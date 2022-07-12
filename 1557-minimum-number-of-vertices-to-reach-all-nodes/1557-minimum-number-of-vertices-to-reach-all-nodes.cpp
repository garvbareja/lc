class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n); vector<int> res;
        for(int i=0;i<edges.size();i++) indegree[edges[i][1]]=true;
        for(int i=0;i<n;i++) if(!indegree[i]) res.push_back(i);
        return res;
    }
};