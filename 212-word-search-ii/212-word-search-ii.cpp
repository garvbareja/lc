class TrieNode{
public:
    vector<TrieNode*> links;
    bool isWord;
    TrieNode(){
        links.resize(26);
        isWord=false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void addword(string& word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->links[word[i]-'a']) node->links[word[i]-'a'] = new TrieNode();
            node=node->links[word[i]-'a'];
        }
        node->isWord=true;
    }
};

class Solution {
public:
    vector<int> x={-1,1,0,0};
    vector<int> y={0,0,-1,1};
    vector<string> ans;
    string cur;
    void dfs(vector<vector<char>>& board,TrieNode* node,int i,int j){
        if(i<0 || i==board.size() || j<0 || j==board[i].size() || board[i][j]=='@' || !node->links[board[i][j]-'a']) return;
        node=node->links[board[i][j]-'a'];
        cur.push_back(board[i][j]);
        if(node->isWord){
            ans.push_back(cur);
            node->isWord=false;
        }
        board[i][j]='@';
        for(int z=0;z<4;z++) dfs(board,node,i+x[z],j+y[z]);
        board[i][j]=cur.back();
        cur.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        Trie trie;
        cur="";
        for(int i=0;i<words.size();i++) trie.addword(words[i]);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                dfs(board,trie.root,i,j);
            }
        }
        return ans;
    }
};