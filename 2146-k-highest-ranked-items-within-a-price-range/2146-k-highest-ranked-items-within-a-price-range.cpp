
class Solution {
public:
    class res{
public:
    int d;
    int p;
    int r;
    int c;
};

class cmp{
public:
    bool operator()(res &a,res &b){
        if(a.d!=b.d) return a.d<b.d;
        if(a.p!=b.p) return a.p<b.p;
        if(a.r!=b.r) return a.r<b.r;
        return a.c<b.c;
    }
};

    bool valid(vector<vector<int>>& g,int i,int j){
        return true;
    }
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& g, vector<int>& price, vector<int>& start, int k){
        queue<pair<int,int>> q;
        priority_queue<res,vector<res>,cmp> pq;
        q.push({start[0],start[1]});
        vector<vector<bool>> vis(g.size(),vector<bool>(g[0].size()));
        vis[start[0]][start[1]]=true;
        int step=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int x=q.front().first; int y=q.front().second; q.pop();
                if(g[x][y]!=1 && price[0]<=g[x][y] && g[x][y]<=price[1]){
                    pq.push({step,g[x][y],x,y});
                    while(pq.size()>k) pq.pop();
                }
                if(x+1<g.size() && g[x+1][y]>0 && !vis[x+1][y]){
                    vis[x+1][y]=true;
                    q.push({x+1,y});
                }
                if(x-1>=0 && g[x-1][y]>0 && !vis[x-1][y]) {q.push({x-1,y}); vis[x-1][y]=true;}
                if(y+1<g[0].size() && g[x][y+1]>0 && !vis[x][y+1]) {q.push({x,y+1}); vis[x][y+1]=true;}
                if(y-1>=0 && g[x][y-1]>0 && !vis[x][y-1]) {q.push({x,y-1}); vis[x][y-1]=true;}
            }
            step++;
        }
        vector<vector<int>> ans(pq.size());
        int indx=pq.size()-1;
        while(!pq.empty()){
            ans[indx]={pq.top().r,pq.top().c};
            indx--;
            pq.pop();
        }
        return ans;
    }
};