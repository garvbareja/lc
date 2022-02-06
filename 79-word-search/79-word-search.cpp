class Solution {
public:
    vector<int> x={-1,1,0,0};
    vector<int> y={0,0,1,-1};
    
    bool dfs(vector<vector<char>>& board,string& word,int i,int j,int index){
        if(index==word.length()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]=='@' || board[i][j]!=word[index]) return false;
        board[i][j]='@';
        for(int z=0;z<4;z++) if(dfs(board,word,i+x[z],j+y[z],index+1)) return true;
        board[i][j]=word[index];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string &word){
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(word[0]==board[i][j]) if(dfs(board,word,i,j,0)) return true;
        return false;
    }
};