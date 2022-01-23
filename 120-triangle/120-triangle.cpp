class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev = triangle[0];
        for(int i=1;i<triangle.size();i++){
            vector<int> cur = triangle[i];
            for(int j=0;j<cur.size();j++){
                if(j==cur.size()-1){cur[j]+=prev[j-1]; continue;}
                cur[j]+=min(prev[max(0,j-1)],prev[j]);
            }
            prev=cur;
            for(auto num:prev) cout<<num<<" ";
        }
        return *min_element(prev.begin(),prev.end());
    }
};