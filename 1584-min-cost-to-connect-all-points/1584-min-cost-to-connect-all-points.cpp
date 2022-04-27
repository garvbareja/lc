class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),cur=0,next,ans=0,nextmin=INT_MAX;
        vector<bool> mst(n);
        vector<int> dis(n,INT_MAX);
        for(int i=0;i<n-1;i++){
            mst[cur]=true;
            int x=points[cur][0],y=points[cur][1];
            nextmin=INT_MAX;
            for(int j=0;j<n;j++){
                if(mst[j]) continue;
                dis[j]=min(dis[j],abs(x-points[j][0])+abs(y-points[j][1]));
                if(dis[j]<nextmin){
                    nextmin=dis[j];
                    next=j;
                }
            }
            cur=next;
            ans+=nextmin;
        }
        return ans;
    }
};