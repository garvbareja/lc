class Solution {
public:
    static bool custom(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<pair<int,int>,int> hash;
        for(int i=0;i<intervals.size();i++) hash[{intervals[i][0],intervals[i][1]}]=i;
        sort(intervals.begin(),intervals.end(),custom);
        vector<int> ans(intervals.size());
        for(int i=0;i<intervals.size();i++){
            int index=hash[{intervals[i][0],intervals[i][1]}];
            int low=i,high=intervals.size()-1;
            int floor=-1;
            while(low<=high){
                int mid=low +(high-low)/2;
                if(intervals[mid][0]<intervals[i][1]) low=mid+1;
                else{
                    floor=mid;
                    high=mid-1;
                }
            }
            if(floor==-1) ans[index]=-1;
            else ans[index]=hash[{intervals[floor][0],intervals[floor][1]}];
        }
        return ans;
    }
};