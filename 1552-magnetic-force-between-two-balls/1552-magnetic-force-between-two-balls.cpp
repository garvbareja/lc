class Solution {
public:
    int score(vector<int>& nums,int force){
        int ball=1; int prevball=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-prevball>=force){
                ball++;
                prevball=nums[i];
            }
        }
        return ball;
    }
    
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int low=1,high=nums.back()-nums[0],mid,res;
        while(low<=high){
            mid=low+(high-low)/2;
            if(score(nums,mid)>=m){
                low=mid+1;
                res=mid;
            }else high=mid-1;
        }
        return res;
    }
};