class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int mn,mx; int i=0,j=0;
        while(i<f.size() && j<s.size()){
            mn=max(f[i][0],s[j][0]);
            mx=min(f[i][1],s[j][1]);
            if(mn<=mx) ans.push_back({mn,mx});
            f[i][1]<s[j][1]?i++:j++;
        }
        return ans;
    }
};