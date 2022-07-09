class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,cursum=0,res=INT_MAX;
        while(i<nums.size()){
            cursum+=nums[i];
            while(cursum>=target){
                res=min(res,i-j+1);
                cursum-=nums[j];
                j++;
            }
            i++;
        }
        return res==INT_MAX?0:res;
    }
};