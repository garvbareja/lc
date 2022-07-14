class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1,res=0,i=0,j=0;
        while(i<nums.size()){
            prod*=nums[i];
            while(j<=i && prod>=k){
                prod/=nums[j];
                j++;
            }
            res+=i-j+1;
            i++;
        }
        return res;
    }
};