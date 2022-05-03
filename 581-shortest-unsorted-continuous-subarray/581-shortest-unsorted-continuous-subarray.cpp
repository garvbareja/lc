class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end()); 
        sort(temp.begin(),temp.end());
        int i=0;
        while(i<temp.size() && temp[i]==nums[i]) i++;
        if(i==temp.size()) return 0;
        int j=nums.size()-1;
        while(j>i && temp[j]==nums[j]) j--;
        return j-i+1;
    }
};