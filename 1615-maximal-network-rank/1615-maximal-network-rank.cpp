class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> adj_mat(n,vector<bool>(n)); vector<int> degree(n);
        for(int i=0;i<roads.size();i++){
            adj_mat[roads[i][0]][roads[i][1]]=true;
            adj_mat[roads[i][1]][roads[i][0]]=true;
            degree[roads[i][0]]+=1; degree[roads[i][1]]+=1;
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=max(res,degree[i]+degree[j]-(int)adj_mat[i][j]);
            }
        }
        return res;
    }
};