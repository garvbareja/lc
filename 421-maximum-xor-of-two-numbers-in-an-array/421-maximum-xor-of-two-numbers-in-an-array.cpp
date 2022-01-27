class Node{
public:
    Node* links[2];
    
    bool contains(int bit){
        return (links[bit]!=nullptr);
    }
    
    void put(int bit){
        links[bit]=new Node();
    }
    
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
private: Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->contains(bit)) node->put(bit);
            node=node->get(bit);
        }
    }
    
    int getmaxxor(int num){
        Node* node=root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->contains(1-bit)){
                ans=ans|(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums){
        Trie trie;
        int ans=0;
        for(int i=0;i<nums.size();i++) trie.insert(nums[i]);
        for(int i=0;i<nums.size();i++) ans=max(ans,trie.getmaxxor(nums[i]));
        return ans;
    }
};