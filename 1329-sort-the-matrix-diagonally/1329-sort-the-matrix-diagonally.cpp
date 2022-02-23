class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.size()==1) return mat;
        //top row
        int m=mat.size(),n=mat[0].size();
        vector<int> process(101);
        for(int i=n-1;i>=0;i--){
            int ti=0,tj=i;
            vector<int> temp;
            while(ti<m && tj<n){
                temp.push_back(mat[ti][tj]); tj++; ti++;
            }
            ti=0;tj=i; sort(temp.begin(),temp.end());
            int indx=0;
             while(ti<m && tj<n){
                mat[ti][tj]=temp[indx]; indx++; tj++; ti++;
            }
        }
        // first col
        for(int i=1;i<m;i++){
            int ti=i,tj=0; vector<int> temp;
            while(ti<m && tj<n){
                temp.push_back(mat[ti][tj]); ti++; tj++;
            }
            sort(temp.begin(),temp.end());
            ti=i;tj=0; int indx=0;
            while(ti<m && tj<n){
                mat[ti][tj]=temp[indx]; indx++; ti++; tj++;
            }
        }
        return mat;
    }
};