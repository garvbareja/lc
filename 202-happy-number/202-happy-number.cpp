class Solution {
public:
    unordered_set<int> hash;
    bool isHappy(int n) {
        if(n==1) return true;
        int cur=0;
        while(n){
            cur+=pow(n%10,2);
            n/=10;
        }
        if(hash.count(cur)) return false;
        hash.insert(cur);
        return isHappy(cur);
    }
};