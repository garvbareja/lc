class Solution {
public:
    bool row[9][9]={};
    bool col[9][9]={};
    bool sq[3][3][9]={};
    
    bool valid(int x,int y,int z){
        if(row[x][z] || col[y][z] || sq[x/3][y/3][z]) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>>& nums,vector<vector<int>>& empty_pos,int i){
        if(i==empty_pos.size()) return true;
        int x=empty_pos[i][0]; int y=empty_pos[i][1];
        for(int z=0;z<9;z++){
            if(valid(x,y,z)){
                nums[x][y]=(z+'1');
                row[x][z]=true;
                col[y][z]=true;
                sq[x/3][y/3][z]=true;
                if(dfs(nums,empty_pos,i+1)) return true;
                nums[x][y]='.';
                row[x][z]=false;
                col[y][z]=false;
                sq[x/3][y/3][z]=false;
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board){
        vector<vector<int>> empty_pos;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int val=board[i][j]-'1';
                    row[i][val]=true;
                    col[j][val]=true;
                    sq[i/3][j/3][val]=true;
                }else{
                    empty_pos.push_back({i,j});
                }
            }
        }
        dfs(board,empty_pos,0);
    }
};