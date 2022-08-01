class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(!k || k==1) return 0;
        int i=0,j=0,product=1,res=0;
        while(i<nums.size()){
            product*=nums[i];
            while(product>=k){
                product/=nums[j];
                j++;
            }
            res+=i-j+1;
            i++;
        }
        return res;
    }
};