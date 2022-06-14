class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,right=n-1,top=0,bottom=n-1;
        vector<vector<int>> res(n,vector<int>(n));
        int count=1; int sq=n*n;
        while(count<=sq){
            for(int i=left;i<=right;i++){
                res[top][i]=count;
                count++;
            } if(count>sq) break;
            top++;
            for(int i=top;i<=bottom;i++){
                res[i][right]=count;
                count+=1;
            } right--;
            for(int i=right;i>=left;i--){
                res[bottom][i]=count;
                count+=1;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                res[i][left]=count;
                count+=1;
            }
            left++;
        }
        return res;
    }
};