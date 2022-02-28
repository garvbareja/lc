class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(!nums.size()) return {};
        int start=nums[0],end=nums[0];
        vector<string> res;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==end+1) end++;
            else{
                if(start==end) res.push_back(to_string(start));
                else res.push_back(to_string(start)+"->"+to_string(end));
                start=nums[i]; end=nums[i];
            }
        }
        if(start==end) res.push_back(to_string(start));
        else res.push_back(to_string(start)+"->"+to_string(end));
        return res;
    }
};