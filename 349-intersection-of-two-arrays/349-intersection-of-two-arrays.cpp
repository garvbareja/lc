class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++) if(!hash.count(nums1[i])) hash.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            if(hash.count(nums2[i])){
                ans.push_back(nums2[i]);
                hash.erase(nums2[i]);
            }
        }
        return ans;        
    }
};