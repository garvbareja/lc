class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f,vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<f.size() && j<s.size()){
            int low = max(f[i][0],s[j][0]);
            int high = min(f[i][1],s[j][1]);
            if(low<=high) ans.push_back({low,high});
            f[i][1]<s[j][1]?i++:j++;
        }
        return ans;
    }
};