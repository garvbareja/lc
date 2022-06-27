class Solution {
public:
    int fib(int n) {
        if(!n) return 0;
        if(n==1) return 1;
        int first=0,second=1;
        int cur=1;
        while(cur!=n){
            int newval=first+second;
            first=second;
            second=newval;
            cur++;
        }
        return second;
    }
};