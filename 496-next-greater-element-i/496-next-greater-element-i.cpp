class Solution {
public:
    vector<int> ngr;
    void solve(vector<int>& nums){
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]) s.pop();
            if(s.empty()) ngr.push_back(-1);
            else ngr.push_back(s.top());
            s.push(nums[i]);
        }
        reverse(ngr.begin(),ngr.end());
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        solve(nums2);
        unordered_map<int,int> hash; vector<int> ans(nums1.size());
        for(int i=0;i<nums2.size();i++) hash[nums2[i]]=i;
        for(int i=0;i<nums1.size();i++) ans[i]=ngr[hash[nums1[i]]];
        return ans;
    }
};