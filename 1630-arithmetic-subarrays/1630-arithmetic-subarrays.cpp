class Solution {
public:
    bool checkarithematic(vector<int>& nums){
        if(nums.size()<=2) return true;
        int d=nums[1]-nums[0];
        for(int i=1;i<nums.size();i++) if(nums[i]-nums[i-1]!=d) return false;
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size());
        for(int i=0;i<l.size();i++){
            vector<int>temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(temp.begin(),temp.end());
            res[i]=checkarithematic(temp);
        }
        return res;
    }
};