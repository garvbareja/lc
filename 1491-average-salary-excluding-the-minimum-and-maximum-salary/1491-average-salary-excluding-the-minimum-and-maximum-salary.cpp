class Solution {
public:
    double average(vector<int>& salary) {
        int mx=salary[0],mn=salary[0],sum=0;
        for(int i=0;i<salary.size();i++){
            sum+=salary[i];
            mx=max(mx,salary[i]);
            mn=min(mn,salary[i]);
        }
        return ((double)(sum-mx-mn))/(salary.size()-2);
    }
};