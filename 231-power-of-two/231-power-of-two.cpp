class Solution {
public:
    bool help(int n){
        if(n<2) return true;
        if(n%2) return false;
        return help(n/2);
    }
    
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        if(!n) return false;
        return help(n);
    }
};