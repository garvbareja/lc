class Solution {
public:
    int bs(vector<int>& nums){
        if(nums[0]<0) return 0;
        if(nums.back()>=0) return -1;
        int low=0,high=nums.size()-1,res=-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<0){
                res=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return res;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int res=-1,ans=0;
        for(int i=0;i<grid.size();i++){
            res=-1;
            res=bs(grid[i]);
            if(res!=-1) ans+=grid[i].size()-res;
        }
        return ans;
    }
};