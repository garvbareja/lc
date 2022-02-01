class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> freq(32); long ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=31;j>=0;j--){
                if((nums[i]>>j)&1) freq[j]++;
            }
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]%3) ans+=pow(2,i);
        }
        return ans;
    }
};