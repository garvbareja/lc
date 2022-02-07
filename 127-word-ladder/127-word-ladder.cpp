class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words){
        bool flag=false;
        for(int i=0;i<words.size();i++){
            if(words[i]==end){
                flag=true;
                break;
            }
        }
        if(!flag) return 0;
        unordered_map<string,vector<string>> adj;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                string pattern = words[i];
                pattern[j]='*';
                if(!adj.count(pattern)) adj[pattern]={words[i]};
                else adj[pattern].push_back(words[i]);
            }
        }
        queue<string> q; q.push(begin);
        unordered_set<string> hash; hash.insert(begin);
        int step=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string front = q.front(); q.pop();
                for(int i=0;i<front.length();i++){
                    string pattern = front;
                    pattern[i]='*';
                    for(int j=0;j<adj[pattern].size();j++){
                        if(!hash.count(adj[pattern][j])){
                            if(adj[pattern][j]==end) return step+2;
                            hash.insert(adj[pattern][j]);
                            q.push(adj[pattern][j]);
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};