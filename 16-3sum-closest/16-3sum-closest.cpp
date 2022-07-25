class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); int i=0,sum,left,right,diff=INT_MAX,cur_sum;
        while(i<nums.size()){
            left=i+1; right=nums.size()-1;
            while(left<right){
                cur_sum=nums[i]+nums[left]+nums[right];
                if(abs(cur_sum-target)<diff){
                    diff=abs(cur_sum-target);
                    sum=cur_sum;
                }
                if(cur_sum<target) left+=1;
                else right-=1;
            }
            i+=1;
        }
        return sum;
    }
};