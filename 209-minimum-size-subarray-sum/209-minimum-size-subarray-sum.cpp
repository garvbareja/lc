class Solution {
public:
    bool possible(vector<int>& nums,int target,int window_size){
        int cursum=0;
        int i=0,j=0;
        while(i<nums.size()){
            cursum+=nums[i];
            if(i-j+1==window_size){
                if(cursum>=target) return true;
                else{
                    cursum-=nums[j];
                    j++;
                }
            }
            i++;
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=1,high=nums.size(),mid,res=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(possible(nums,target,mid)){
                res=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return res;
    }
};