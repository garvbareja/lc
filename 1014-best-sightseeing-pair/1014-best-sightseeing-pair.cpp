class Solution {
public:
    vector<int> tru,fal;
    int helper(vector<int>& nums,int i,bool flag){
        if(i==nums.size()) return 0;
        if(flag){
            if(i==nums.size()-1) return 0;
            if(tru[i]!=-1) return tru[i];
            return tru[i]=max(helper(nums,i+1,true),helper(nums,i+1,false)+nums[i]+i);
        }else{
            if(i==nums.size()-1) return nums[i]-i;
            if(fal[i]!=-1) return fal[i];
            return fal[i]=max(nums[i]-i,helper(nums,i+1,false));
        }
    }
    
    int maxScoreSightseeingPair(vector<int>& nums) {
        tru.resize(nums.size(),-1);
        fal.resize(nums.size(),-1);
        return helper(nums,0,true);
    }
};