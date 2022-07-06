class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int res=INT_MAX;
        vector<int> prev(nums.back().begin(),nums.back().end()); vector<int> cur(nums[0].size());
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=nums[0].size()-1;j>=0;j--){
                cur[j]=prev[j];
                if(j-1>=0) cur[j]=min(cur[j],prev[j-1]);
                if(j+1<nums[0].size()) cur[j]=min(cur[j],prev[j+1]);
                cur[j]+=nums[i][j];
                if(!i) res=min(res,cur[j]);
            }
            prev=cur;
        }
        return *min_element(prev.begin(),prev.end());
    }
};