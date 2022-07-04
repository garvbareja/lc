class Solution {
public:
    int minMutation(string& start, string& end, vector<string>& bank) {
        queue<string> q; q.push(start); unordered_set<string> hash;
        vector<char> gene={'A','C','G','T'};
        for(int i=0;i<bank.size();i++) hash.insert(bank[i]); hash.erase(start);
        int res=0; char og; string temp="";
        while(!q.empty()){
            int size=q.size();
            while(size--){
                temp=q.front(); q.pop();
                if(temp==end) return res;
                for(int i=0;i<8;i++){
                    for(int j=0;j<4;j++){
                        og=temp[i];
                        temp[i]=gene[j];
                        if(hash.count(temp)){
                            hash.erase(temp);
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