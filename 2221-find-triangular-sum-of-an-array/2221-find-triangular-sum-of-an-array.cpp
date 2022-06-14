class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int cap=nums.size()-1; int prevval,newval;
        while(cap){
            prevval=nums[cap];
            for(int i=cap-1;i>=0;i--){
                if(i!=0) newval=nums[i];
                nums[i]+=prevval;
                nums[i]%=10;
                if(i!=0) prevval=newval;
            }
            cap--;
        }
        return nums[0];
    }
};