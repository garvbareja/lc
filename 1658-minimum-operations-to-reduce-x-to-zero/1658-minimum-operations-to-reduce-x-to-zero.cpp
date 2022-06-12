class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++) totalsum+=nums[i];
        int target=totalsum-x;
        if(target==0) return nums.size();
        if(target<0) return -1;
        int i=0,j=0,cursum=0,maxx=-1;
        while(i<nums.size()){
            cursum+=nums[i];
            if(cursum==target){
                maxx=max(maxx,i-j+1);
            }
            while(cursum>=target){
                if(cursum==target) maxx=max(maxx,i-j+1);
                cursum-=nums[j];
                j++;
                
            }
            i++;
        }
        if(maxx==-1) return -1;
        return nums.size()-maxx;
    }
};