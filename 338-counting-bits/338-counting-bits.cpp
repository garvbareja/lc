class Solution {
public:
    int countbits(int n){
        int ones=0;
        for(int i=31;i>=0;i--) if((n>>i)&1) ones++;
        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++) ans[i]=countbits(i);
        return ans;
    }
};