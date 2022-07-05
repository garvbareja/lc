class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<=2) return true;
        int low=0,high=(int)sqrt(c);
        while(low<=high){
            long long int cur=(long)low*low+high*high;
            if(cur==c) return true;
            else if(cur<c) low++;
            else high--;
        }
        return false;
    }
};