class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        vector<int> nsr(nums.size()),nsl(nums.size());
        stack<pair<int,int>> s; s.push({-1,-1});
        for(int i=0;i<nums.size();i++){
            while(s.top().first>=nums[i]) s.pop();
            nsl[i]=s.top().second;
            s.push({nums[i],i});
        }
        while(!s.empty()) s.pop(); s.push({-1,nums.size()});
        for(int i=nums.size()-1;i>=0;i--){
            while(s.top().first>=nums[i]) s.pop();
            nsr[i]=s.top().second;
            s.push({nums[i],i});
        }
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            ans=max(ans,(nsr[i]-nsl[i]-1)*nums[i]);
        }
        return ans;
    }
};