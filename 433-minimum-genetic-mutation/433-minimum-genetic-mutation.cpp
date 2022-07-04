class Solution {
public:
    int minMutation(string& start, string& end, vector<string>& bank) {
        unordered_set<string> vis; queue<string> q; q.push(start); vis.insert(start);
        string temp=""; vector<char> gene={'A','C','G','T'}; unordered_set<string> hash;
        for(int i=0;i<bank.size();i++) hash.insert(bank[i]);
        int res=0; char og;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                temp=q.front(); q.pop();
                if(temp==end) return res;
                for(int i=0;i<8;i++){
                    for(int j=0;j<4;j++){
                        og=temp[i];
                        temp[i]=gene[j];
                        if(!vis.count(temp) && hash.count(temp)){
                            vis.insert(temp);
                            q.push(temp);
                        }
                        temp[i]=og;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};