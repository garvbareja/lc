class Solution {
public:
    bool check(string& s,string& p,vector<int>& nums,int k){
        for(int i=0;i<k;i++) s[nums[i]]-='a';
        int i=0,j=0;
        while(i<s.length() && j<p.length()){
            if(s[i]==p[j]) j++;
            i++;
        }
        for(int i=0;i<k;i++) s[nums[i]]+='a';
        return j==p.length();
    }
    
    int maximumRemovals(string &s, string &p, vector<int>& nums) {
        int low=0,high=nums.size(),mid,res;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(s,p,nums,mid)){
                res=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return res;
    }
};