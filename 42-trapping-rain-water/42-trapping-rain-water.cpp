class Solution {
public:
    vector<int> ngl_function(vector<int>& nums){
        int maxsofar=nums[0];
        vector<int> res; res.push_back(-1);
        for(int i=1;i<nums.size();i++){
            if(maxsofar>nums[i]) res.push_back(maxsofar);
            else{
                maxsofar=nums[i];
                res.push_back(-1);
            }
        }
        return res;
    }
    
    vector<int> ngr_function(vector<int>& nums){
        vector<int> res; res.push_back(-1);
        int maxsofar=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            if(maxsofar>nums[i]) res.push_back(maxsofar);
            else{
                maxsofar=nums[i];
                res.push_back(-1);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    int trap(vector<int>& nums) {
        int res=0;
        vector<int> ngr=ngr_function(nums);
        vector<int> ngl=ngl_function(nums);
        for(int i=0;i<nums.size();i++){
            if(ngr[i]!=-1 && ngl[i]!=-1) res+=min(ngr[i],ngl[i])-nums[i];
        }
        return res;
    }
};