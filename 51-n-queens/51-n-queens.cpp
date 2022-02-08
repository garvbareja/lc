class Solution {
public:
    vector<string> cur;
    vector<vector<string>> ans;
    unordered_set<int> col;
    unordered_set<int> neg_dia;
    unordered_set<int> pos_dia;
    
    bool valid(int i,int j){
        if(col.count(j) || pos_dia.count(i+j) || neg_dia.count(i-j)) return false;
        return true;
    }
    
    void dfs(int n,int row){
        if(row==n){
            ans.push_back(cur);
            return;
        }
        for(int c=0;c<n;c++){
            if(valid(row,c)){
                cur[row][c]='Q';
                col.insert(c); pos_dia.insert(row+c); neg_dia.insert(row-c);
                dfs(n,row+1);
                cur[row][c]='.';
                col.erase(c); pos_dia.erase(row+c); neg_dia.erase(row-c);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n){
        string temp; temp.append(n,'.');
        cur.resize(n,temp);
        dfs(n,0);
        return ans;
    }
};