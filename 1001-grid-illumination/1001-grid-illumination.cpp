class Solution {
public:
    bool valid(int n,int i,int j){
        if(i<0 || i>=n || j<0 || j>=n) return false;
        return true;
    }
    
    vector<int> gridIllumination(int n, vector<vector<int>>& l, vector<vector<int>>& q){
        vector<int> ans(q.size());
        unordered_map<int,int> pd,nd,r,c;
        set<pair<int,int>> s;
        for(int i=0;i<l.size();i++){
            if(s.count({l[i][0],l[i][1]})) continue;
            r[l[i][0]]++; c[l[i][1]]++; pd[l[i][0]+l[i][1]]++; nd[l[i][0]-l[i][1]]++; s.insert({l[i][0],l[i][1]});
        }
        vector<int> x={0,0,1,1,1,0,-1,-1,-1};
        vector<int> y={0,1,1,0,-1,-1,-1,0,1};
        for(int i=0;i<q.size();i++){
            if(r[q[i][0]]>0 || c[q[i][1]]>0 || pd[q[i][0]+q[i][1]]>0 || nd[q[i][0]-q[i][1]]>0){
                ans[i]=1;
                for(int z=0;z<9;z++){
                    int ni=q[i][0]+x[z],nj=q[i][1]+y[z];
                    if(!valid(n,ni,nj)) continue;
                    if(s.count({ni,nj})){
                        s.erase({ni,nj});
                        r[ni]--; c[nj]--; pd[ni+nj]--; nd[ni-nj]--;
                    }
                }
            }else ans[i]=0;
        }
        return ans;
    }
};