class Solution {
public:
    int ans=0;
    unordered_set<int> col;
    unordered_set<int> neg_dia;
    unordered_set<int> pos_dia;
    
    bool valid(int i,int j){
        if(col.count(j) || pos_dia.count(i+j) || neg_dia.count(i-j)) return false;
        return true;
    }
    
    void dfs(int n,int row){
        if(row==n){
            ans++;
            return;
        }
        for(int c=0;c<n;c++){
            if(valid(row,c)){
                col.insert(c); pos_dia.insert(row+c); neg_dia.insert(row-c);
                dfs(n,row+1);
                col.erase(c); pos_dia.erase(row+c); neg_dia.erase(row-c);
            }
        }
    }
    
    int totalNQueens(int n) {
        dfs(n,0);
        return ans;
    }
};