class Solution {
public:
    int countPairs(vector<int>& nums){
        int mod=1000000007;
        unordered_map<int,int> hash;
        long res=0;
        for(int i=0;i<nums.size();i++){
            int power=1;
            for(int j=0;j<22;j++){
                if(hash.count(power-nums[i])){
                    res+=hash[power-nums[i]];
                    res%=mod;
                }
                power*=2;
            }
            hash[nums[i]]++;
        }
        return res;
    }
};