class Solution {
public:
    bool possible(vector<int>& nums,double hour,int speed){
        double time=0;
        for(int i=0;i<nums.size();i++){
            time=ceil(time);
            time+=(double)nums[i]/speed;
            if(time>hour) return false;

        }
        return time<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7,mid,res=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(possible(dist,hour,mid)){
                high=mid-1;
                res=mid;
            }else low=mid+1;
        }
        return res;
    }
};