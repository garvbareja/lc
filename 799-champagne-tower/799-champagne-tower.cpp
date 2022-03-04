class Solution {
public:
    double champagneTower(int poured, int query_row, int query_col) {
        vector<vector<double>> drink(query_row+2,vector<double>(query_row+2));
        drink[0][0]=(double)poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                if(drink[i][j]>1.0){
                    drink[i+1][j]+=(drink[i][j]-1.0)/2.0;
                    drink[i+1][j+1]+=(drink[i][j]-1.0)/2.0;
                }
            }
        }
        return drink[query_row][query_col]>=1?1.0:drink[query_row][query_col];
    }
};