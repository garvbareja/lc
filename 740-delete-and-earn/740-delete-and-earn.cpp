class Solution {    
public:    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> toprocess;
        for(int i=0;i<nums.size();i++){
            if(!hash.count(nums[i])) toprocess.push_back(nums[i]);
            hash[nums[i]]++;
        }
        sort(toprocess.begin(),toprocess.end());
        int take=0,skip=0; int dprev=0,prev=0,cur;
        for(int i=toprocess.size()-1;i>=0;i--){
            take=toprocess[i]*hash[toprocess[i]]; skip=prev;
            if(i+1<toprocess.size() && toprocess[i+1]==toprocess[i]+1) take+=dprev;
            else take+=prev;
            cur=max(take,skip);
            dprev=prev;
            prev=cur;
        }
        return prev;
    }
};