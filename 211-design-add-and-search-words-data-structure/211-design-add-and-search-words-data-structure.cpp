class Node{
public:
    Node* links[26];
    bool flag = false;
    
    Node* get(char c){
        return links[c-'a'];
    }
    
    void put(char c){
        links[c-'a'] = new Node();
    }
};


class WordDictionary {
private: Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->get(word[i])) node->put(word[i]);
            node=node->get(word[i]);
        }
        node->flag=true;
    }
    
    bool dfs(string& word,int i,Node* node){
        if(i==word.length()) return node->flag;
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(node->links[j]) if(dfs(word,i+1,node->links[j])) return true;
            }
        }else{
            if(node->get(word[i])) if(dfs(word,i+1,node->get(word[i]))) return true;
        }
        return false;
    }
    
    bool search(string word) {
        if(dfs(word,0,root)) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */