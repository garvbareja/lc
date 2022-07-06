class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans={1};
        int x=0,y=0,z=0;
        while(n!=1){
            ans.push_back(min(min(ans[x]*2,ans[y]*3),ans[z]*5));
            if(ans[x]*2==ans.back()) x++;
            if(ans[y]*3==ans.back()) y++;
            if(ans[z]*5==ans.back()) z++;
            n--;
        }
        return ans.back();
    }
};