class Solution {
public:
    int tribonacci(int n) {
        if(!n) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int cur=2,first=0,second=1,third=1;
        while(cur!=n){
            int newval=first+second+third;
            first=second;
            second=third;
            third=newval;
            cur++;
        }
        return third;
    }
};