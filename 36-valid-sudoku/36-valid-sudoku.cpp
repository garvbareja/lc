class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={},col[9][9]={},sq[3][3][9]={};
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(isdigit(board[i][j])){
                    int num=board[i][j]-'1';
                    if(row[i][num]++ || col[j][num]++ || sq[i/3][j/3][num]++) return false;
                }
        return true;
    }
};