class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a'); k-=n; int i=n-1;
        while(k){
            k+=1;
            if(k/26){
                res[i]='z'; k-=26; --i;
            }else{
                res[i]=96+k; k=0;
            }
        }
        return res;
    }
};