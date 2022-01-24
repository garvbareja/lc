class Solution {
public:
    unordered_set<string> hash;
    int openLock(vector<string>& deadends, string target){
        for(int i=0;i<deadends.size();i++){
            if(deadends[i]=="0000") return -1;
            hash.insert(deadends[i]);
        }
        queue<string> q; q.push("0000"); hash.insert("0000");
        int moves=0;
        vector<int> x = {-1,1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string front = q.front(); q.pop();
                if(front==target) return moves;
                for(int i=0;i<4;i++){
                    string temp = front;
                    for(int j=0;j<2;j++){
                        front[i]=(((front[i]-'0')+10+x[j])%10 + '0');
                        if(!hash.count(front)){
                            hash.insert(front);
                            q.push(front);
                        }
                        front=temp;
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};