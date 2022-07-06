class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;
        for(int i=2;i<=n;i++){
            arr[i] = INT_MAX;
            for(int j=1;j<=sqrt(i);j++){
                arr[i] = min(arr[i],arr[i-(j*j)]+1);
            }
        }
        return arr[n];
    }
};