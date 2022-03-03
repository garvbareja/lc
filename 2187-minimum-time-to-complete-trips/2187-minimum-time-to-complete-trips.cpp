class Solution {
public:
    long long minimumTime(vector<int>& time, long long totalTrips) {
        if(time.size()==1) return time[0]*totalTrips;
        long long int low=1,high=1e14,trips=0,mid,ans;
        while(low<=high){
            mid=low+(high-low)/2;
            trips=0;
            for(int i=0;i<time.size();i++){
                if(mid>=time[i]) trips+=(mid/time[i]);
            }
            if(trips>=totalTrips){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};