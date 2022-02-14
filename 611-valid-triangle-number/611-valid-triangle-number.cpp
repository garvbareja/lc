class Solution {
public:
    int triangleNumber(vector<int>& nums){
        sort(nums.begin(),nums.end()); int i=0,ans=0;
        cout<<nums.size();
        while(i<(int)nums.size()-2){
            for(int j=i+1;j<(int)nums.size()-1;j++){
                int low=j+1,high=nums.size()-1;
                int ceil=-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(nums[i]+nums[j]>nums[mid]){
                        ceil=mid;
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }
                if(ceil==-1) continue;
                ans+=ceil-j;
            }
            i++;
        }
        return ans;
    }
};