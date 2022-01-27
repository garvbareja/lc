class Node{
public:
    Node* links[26] ;
    bool flag=false;
    
    bool containskey(char c){
        return links[c-'a'];
    }
    
    void put(char c,Node* node){
        links[c-'a'] = node;
    }
    
    Node* get(char c){
        return links[c-'a'];
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string words) {
        Node* node = root;
        for(int i=0;i<words.length();i++){
            if(!(node->containskey(words[i]))) node->put(words[i],new Node());
            node=node->get(words[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
            }else return false;
        }
        return node->flag;
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
            }else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */