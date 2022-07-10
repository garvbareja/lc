class Solution {
public:
    int score(vector<int>& nums,double div){
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=ceil(nums[i]/div);
            if(res>=INT_MAX) return INT_MAX;
        }
        return res;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end()),mid,res;
        while(low<=high){
            mid=low+(high-low)/2;
            if(score(nums,mid)<=threshold){
                res=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return res;
    }
};