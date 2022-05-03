class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum=0; int i=0;
        for(i=0;i<k;i++) sum+=nums[i]; int maxsum=sum;
        i--;
        cout<<sum<<"\n";
        for(int ii=nums.size()-1;ii>nums.size()-1-k;ii--){
            cout<<i;
            sum+=nums[ii]; sum-=nums[i--];
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};