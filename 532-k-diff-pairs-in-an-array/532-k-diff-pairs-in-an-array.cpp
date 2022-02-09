class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int count=0;
        for(auto n: nums) hash[n]++;
       
        for(auto it: hash)
        {
            if(k==0 && it.second>1) count++;
            if(k!=0 && hash.count(it.first-k)==1) count++;
        }
        return count;
    }
};