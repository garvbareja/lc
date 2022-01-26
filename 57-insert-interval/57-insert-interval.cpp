class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(),intervals.end(),comp);
        intervals.push_back({INT_MAX,INT_MAX});
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=prev[1]) prev[1]=max(prev[1],intervals[i][1]);
            else{
                ans.push_back(prev);
                prev[0]=intervals[i][0]; prev[1]=intervals[i][1];
            }
        }
        return ans;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};