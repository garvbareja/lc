class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        for(int i=31;i>=0;i--){
            if(((1<<i)&x)!=((1<<i)&y)) ans++;
        }
        return ans;
    }
};