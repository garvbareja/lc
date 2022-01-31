class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int res=0;
        for(int i=0;i<acc.size();i++){
            int cur=0;
            for(int j=0;j<acc[i].size();j++) cur+=acc[i][j];
            res=max(res,cur);
        }
        return res;
    }
};