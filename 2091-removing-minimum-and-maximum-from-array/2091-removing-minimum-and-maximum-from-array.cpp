class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mnindex=0,mn=nums[0],mx=nums[0],mxindex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mn){
                mn=nums[i];
                mnindex=i;
            }
            if(nums[i]>mx){
                mx=nums[i];
                mxindex=i;
            }
        }
        int removeleft=max(mnindex,mxindex)+1;
        int removeright=nums.size()-min(mnindex,mxindex);
        int n=nums.size();
        int res=min(removeleft,removeright);
        if(mnindex<mxindex) res=min(res,mnindex+1+n-mxindex);
        else res=min(res,mxindex+1+n-mnindex);
        return res;
    }
};