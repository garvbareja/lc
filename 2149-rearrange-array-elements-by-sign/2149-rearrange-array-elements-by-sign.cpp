class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int x=0,y=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ans[y]=nums[i];
                y+=2;
            }else{
                ans[x]=nums[i];
                x+=2;
            }
        }
        return ans;
    }
};