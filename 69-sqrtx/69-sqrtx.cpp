class Solution {
public:
    int mySqrt(int x){
        if(x<=1) return x;
        int low=0,high=x/2;
        int floor=-1;
        while(low<=high){
            long mid = low+(high-low)/2;
            if(mid*mid==x) return mid;
            if(mid*mid<x){
                floor=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return floor; 
    }
};