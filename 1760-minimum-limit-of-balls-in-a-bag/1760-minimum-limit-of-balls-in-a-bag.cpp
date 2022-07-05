class Solution {
public:
    bool possible(vector<int>& nums,int cap,int maxop){
        int op=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<cap) continue;
            op+=(nums[i])/cap;
            if(!(nums[i]%cap)) op-=1;
            if(op>maxop) return false;
        }
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxop) {
        int low=1,high=*max_element(nums.begin(),nums.end()),mid,res;
        while(low<=high){
            mid=low+(high-low)/2;
            if(possible(nums,mid,maxop)){
                res=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return res;
    }
};