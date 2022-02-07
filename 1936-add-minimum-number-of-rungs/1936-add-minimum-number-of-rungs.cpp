class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int prev=0;
        int ans=0;
        for(int i=0;i<rungs.size();i++){
            int gap=rungs[i]-prev;
            ans+=(gap-1)/dist;
            prev=rungs[i];
        }
        return ans;
    }
};