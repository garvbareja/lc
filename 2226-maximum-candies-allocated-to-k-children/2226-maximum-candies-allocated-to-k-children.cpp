class Solution {
public:
    bool possible(vector<int>& nums,long long k,int pilesize){
        long long int res=0;
        for(int i=0;i<nums.size();i++) if(nums[i]>=pilesize) res+=nums[i]/pilesize;
        return res>=k;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,high=*max_element(candies.begin(),candies.end()),mid,res=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(possible(candies,k,mid)){
                res=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return res;
    }
};