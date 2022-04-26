// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n,int low=0,int mid=0,int res=0) {
        while(low<=n){
            mid=low+(n-low)/2;
            if(isBadVersion(mid)){ res=mid; n=mid-1;}
            else low=mid+1;
        }
        return res;
    }
};