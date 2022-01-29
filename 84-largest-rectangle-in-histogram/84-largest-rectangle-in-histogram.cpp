class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        vector<int> calc(nums.size());
        stack<pair<int,int>> s; s.push({-1,nums.size()});
        for(int i=nums.size()-1;i>=0;i--){
            while(s.top().first>=nums[i]) s.pop();
            calc[i]=s.top().second-1;
            s.push({nums[i],i});
        }
        while(!s.empty()) s.pop(); s.push({-1,-1});
        for(int i=0;i<nums.size();i++){
            while(s.top().first>=nums[i]) s.pop();
            calc[i]-=s.top().second;
            s.push({nums[i],i});
        }
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            ans=max(ans,(calc[i])*nums[i]);
        }
        return ans;
    }
};