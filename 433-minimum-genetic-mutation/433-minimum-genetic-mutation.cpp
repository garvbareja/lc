class Solution {
public:
    int minMutation(string &start, string &end, vector<string>& bank) {
        unordered_set<string> hash;
        for(int i=0;i<bank.size();i++) hash.insert(bank[i]); hash.erase(start);
        queue<string> q; q.push(start); string cur=""; int mut=0;
        vector<char> temp={'A','C','G','T'};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                cur=q.front(); q.pop();
                if(cur==end) return mut;
                for(int i=0;i<cur.length();i++){
                    char og=cur[i];
                    for(int j=0;j<4;j++){
                        cur[i]=temp[j];
                        if(hash.count(cur)){
                            q.push(cur);
                            hash.erase(cur);
                        }
                    }
                    cur[i]=og;
                }
            }
            mut+=1;
        }
        return -1;
    }
};