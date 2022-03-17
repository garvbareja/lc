class Solution {
public:
    int numOfPairs(vector<string>& nums, string &t) {
        unordered_map<string,int> hash;
        int res=0; string substring;
        for(int i=0;i<nums.size();i++) hash[nums[i]]++;
        for(int i=0;i<nums.size();i++){
            if(nums[i].size()<t.length()){
                if(nums[i][0]!=t[0]) continue;
                substring=t.substr(nums[i].size(),t.length()-1);
                if(hash.count(substring) && nums[i]+substring==t){
                    if(nums[i]==substring) res+=hash[substring]-1;
                    else res+=hash[substring];
                }
            }
        }
        return res;
    }
};