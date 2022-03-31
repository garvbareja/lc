class Solution {
public:
    bool valid(vector<int>& weights, int days, int mx){
        int count = 1;
        int current = 0;
        for(auto i:weights){
            current += i;
            if(current>mx){
                current = i;
                count++;
            }
        if(count>days) return false;
        }
        return true;
    }

    int splitArray(vector<int>& weights, int days) {
        int start = INT_MIN;
        int end = 0;
        int mid;
        int ans = -1;
        for(auto i:weights){
            end += i;
            if(start<i) start = i;
        }
        while(start<=end){
            mid = (start+end)/2;
            if(valid(weights,days,mid)){
                ans = mid;
                end  = mid-1;
                continue;
            }
            start = mid+1;
        }
        return ans;
    }
};