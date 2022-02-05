class Solution {
public:
    bool isPerfectSquare(int num){
        if(num==1) return true;
        int low=1;
        int high=num/2;
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(num==(mid*mid)) return true;
            if(num<(mid*mid)) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};