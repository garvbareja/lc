class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end(),cmp);
        int count=0; int left=interval[0][0]; int right=interval[0][1];
        for(int i=1;i<interval.size();i++){
            if(left<=interval[i][0] && interval[i][1]<=right) count++;
            else{
                left=interval[i][0]; right=interval[i][1];
            }
        }
        return interval.size()-count;
    }
};