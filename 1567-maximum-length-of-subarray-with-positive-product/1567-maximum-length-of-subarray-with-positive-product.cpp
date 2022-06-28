class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]<=0) return 0;
            else return 1;
        }
        int prevpos=0,prevneg=0,curpos,curneg,res=0;
        if(nums.back()<0) prevneg=1;
        if(nums.back()>0) prevpos=1;
        res=max(prevneg,prevpos);
        for(int i=nums.size()-2;i>=0;i--){
            curpos=0; curneg=0;
            if(nums[i]>0){
                curpos=1+prevpos;
                if(prevneg) curneg=1+prevneg;
            }
            if(nums[i]<0){
                if(prevneg) curpos=1+prevneg;
                curneg=1+prevpos;
            }
            res=max(res,curpos);
            prevpos=curpos;
            prevneg=curneg;
        }
        return res;
    }
};