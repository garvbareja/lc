class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2) return 0;
        int ans=0,count=1;
        int diff=nums[1]-nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==diff) count++;
            else{
                if(count>=3) ans+=(count-1)*(count-2)/2;
                diff=nums[i]-nums[i-1];
                count=2;
            }
        }
        if(count>=3) ans+=(count-1)*(count-2)/2;
        return ans;
    }
};