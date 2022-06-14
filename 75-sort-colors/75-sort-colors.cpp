class Solution {
public:
    void sortColors(vector<int>& A) {
        int nextzero=0,second=A.size()-1;
        int i=0;
        while(i<=second){
            if(A[i]==0) swap(A[i++],A[nextzero++]);
            else if(A[i]==2) swap(A[i],A[second--]);
            else i++;
        }
    }
};