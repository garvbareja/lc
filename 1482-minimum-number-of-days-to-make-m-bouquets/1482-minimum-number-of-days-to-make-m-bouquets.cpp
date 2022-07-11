class Solution {
public:
    int score(vector<int>& nums,int curday,int k){
        int tempk=k,res=0;
        for(int i=0;i<nums.size();i++){
            if(curday>=nums[i]) tempk-=1;
            else tempk=k;
            if(!tempk){
                tempk=k;
                res++;
            }
        }
        return res;
    }
    
    int minDays(vector<int>& nums, int m, int k) {
        int low=1,high=*max_element(nums.begin(),nums.end()),mid,res=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(score(nums,mid,k)>=m){
                res=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return res;
    }
};