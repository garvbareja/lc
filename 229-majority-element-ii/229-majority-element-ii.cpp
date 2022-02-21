class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first=INT_MAX,second=INT_MAX,fcount=0,scount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==first) fcount++;
            else if(nums[i]==second) scount++;
            else if(!fcount){first=nums[i]; fcount++;}
            else if(!scount){second=nums[i]; scount++;}
            else{fcount--;scount--;}
        }
        fcount=0,scount=0;
        for(int i=0;i<nums.size();i++){
            if(first==nums[i]) fcount++;
            if(second==nums[i]) scount++;
        }
        vector<int> ans;
        if(fcount>nums.size()/3) ans.push_back(first);
        if(scount>nums.size()/3) ans.push_back(second);
        return ans;
    }
};