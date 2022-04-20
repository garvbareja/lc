class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int low=0,high=nums.size()-1,index=nums.size()-1;
        while(low<=high){
            int sq1=nums[low]*nums[low];
            int sq2=nums[high]*nums[high];
            // cout<<sq1<<" "<<sq2<<"\n";
            if(sq1>sq2) low++;
            else high--;
            sq1=max(sq1,sq2);
            res[index--]=sq1;
        }
        return res;
    }
};