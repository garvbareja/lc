class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        int nrow = 2;
        while(nrow != numRows){
            vector<int> smallans(nrow+1,1);
            for(int i=1;i<nrow;i++){
                smallans[i] = ans.back()[i] + ans.back()[i-1];
            }
            ans.push_back(smallans);
            nrow++;
        }
        return ans;
    }
};