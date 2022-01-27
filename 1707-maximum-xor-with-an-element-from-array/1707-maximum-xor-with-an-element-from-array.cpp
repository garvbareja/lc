class Node{
public:
    Node* links[2];
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit){
        links[bit]=new Node();
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
            if(!node->get(bit)) node->put(bit);
            node=node->get(bit);
        }
    }
    
    int getmax(int num){
        int ans = 0;
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->get(1-bit)){
                ans = ans | (1<<i);
                node=node->get(1-bit);
            }else node=node->get(bit);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>> offq;
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++) offq.push_back({queries[i][1],{queries[i][0],i}});
        sort(nums.begin(),nums.end()); sort(offq.begin(),offq.end());
        int it=0;
        Trie trie;
        for(int i=0;i<offq.size();i++){
            int xi = offq[i].second.first;
            int mi = offq[i].first;
            int indx = offq[i].second.second;
            while(it<nums.size() && nums[it]<=mi){
                trie.insert(nums[it]);
                it++;
            }
            if(it==0) ans[indx]=-1;
            else ans[indx]=trie.getmax(xi);
        }
        return ans;
    }
};