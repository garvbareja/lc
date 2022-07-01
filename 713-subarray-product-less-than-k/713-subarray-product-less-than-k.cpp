class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<2) return 0;
        int product=1,i=0,j=0,res=0;
        while(i<nums.size()){
            product*=nums[i];
            if(product<k) res+=i-j+1;
            else{
                while(product>=k){
                    product/=nums[j];
                    j++;
                }
                res+=i-j+1;
            }
            i++;
        }
        return res;
    }
};