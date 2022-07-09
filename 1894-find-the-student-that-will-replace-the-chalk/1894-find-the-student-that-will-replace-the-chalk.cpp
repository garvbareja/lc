class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long> prefix_sum; long cursum=0;
        for(int i=0;i<chalk.size();i++){
            cursum+=chalk[i];
            prefix_sum.push_back(cursum);
        }
        k%=prefix_sum.back();
        int low=0,high=prefix_sum.size()-1,mid,res;
        while(low<=high){
            mid=low+(high-low)/2;
            if(k==prefix_sum[mid]) return mid+1;
            if(prefix_sum[mid]>k){
                high=mid-1;
                res=mid;
            }else low=mid+1;
        }
        return res;
    }
};