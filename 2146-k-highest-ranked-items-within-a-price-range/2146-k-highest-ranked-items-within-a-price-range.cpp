class cmp{
public:
    bool operator()(vector<int>& a,vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        if(a[1]!=b[1]) return a[1]<b[1];
        if(a[2]!=b[2]) return a[2]<b[2];
        return a[3]<b[3];
    }
};

class Solution {
public:
    int low,high,cap;
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    
    bool valid(vector<vector<int>>& g,int i,int j){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || !g[i][j]) return false;
        return true;
    }
    
    void bfs(vector<vector<int>>& g,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        int step=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first; int y=q.front().second; q.pop();
                if(g[x][y]){
                    if(g[x][y]!=1 && low<=g[x][y] && g[x][y]<=high){
                        pq.push({step,g[x][y],x,y});
                        if(pq.size()>cap) pq.pop();
                    }
                g[x][y]=0;
                if(valid(g,x+1,y)) q.push({x+1,y});
                if(valid(g,x-1,y)) q.push({x-1,y});
                if(valid(g,x,y-1)) q.push({x,y-1});
                if(valid(g,x,y+1)) q.push({x,y+1});
            }}
            step++;
        }
    }
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k){
        cap=k;low=pricing[0];high=pricing[1];
        bfs(grid,start[0],start[1]);
        vector<vector<int>> ans(pq.size());
        int indx=pq.size()-1;
        while(!pq.empty()){
            ans[indx]={pq.top()[2],pq.top()[3]};
            indx--;
            pq.pop();
        }
        return ans;
    }
};