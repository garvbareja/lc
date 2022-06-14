class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int upto=nums.size()/2; bool flag=false;
        while(upto){
            flag=false; int cur=0;
            for(int i=0;i<(upto*2);i+=2){
                if(flag){
                    nums[cur++]=max(nums[i],nums[i+1]);
                    flag=false;
                }else{
                    nums[cur++]=min(nums[i],nums[i+1]);
                    flag=true;
                }
            }
            upto/=2;
        }
        return nums[0];
    }
};