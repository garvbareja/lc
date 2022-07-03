class Solution {
public:
    int solve(vector<int>& nums,int target){
        int res=0;
        for(int i=0;i<nums.size();i++) if(nums[i]>=target) res++;
        return res;
    }
    
    int specialArray(vector<int>& nums) {
        int low=1,high=101,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            int res=solve(nums,mid);
            if(res==mid) return res;
            if(res<mid) high=mid-1;
            else low=mid+1;
            cout<<1;
        }
        return -1;
    }
};