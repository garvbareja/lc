class Solution {
public:
    int findParent(int v,vector<int>& parent){
        if(parent[v]==v) return v;
        else return parent[v]=findParent(parent[v],parent);
    }

    void unionSet(int u,int v,vector<int>& parent,vector<int>& rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }else if(rank[v]>rank[u]){
            parent[u]=v;
        }else{
            parent[u]=v;
            rank[v]+=1;
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();
        vector<int> parent(m*n,-1),rank(m*n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) parent[i*n+j]=i*n+j;
            }
        }
        
        for(int i=0;i<m;i++){
            int j=0;
            for(;j<n;j++){
                if(grid[i][j]==1) break;
            }
            int jj=j;
            j+=1;
            for(;j<n;j++){
                if(grid[i][j]) unionSet(i*n+jj,i*n+j,parent,rank);
            }
        }
        
        for(int j=0;j<n;j++){
            int i=0;
            for(;i<m;i++){
                if(grid[i][j]) break;
            }
            int ii=i;
            i+=1;
            for(;i<m;i++){
                if(grid[i][j]) unionSet(ii*n+j,i*n+j,parent,rank);
            }
        }

        int ans=0;
        for(int i=0;i<parent.size();i++){
            if(rank[i]>0 || (parent[i]!=-1 && parent[i]!=i)) ans++;
        }
        return ans;
    }
};