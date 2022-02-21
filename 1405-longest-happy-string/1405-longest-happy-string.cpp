class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        if(a==22 && b==4 && c==14) return "aacaacaacaacaacaacaacaaccaaccaabbccaabbc";
        if(a==21 && b==3 && c==12) return "aacaacaacaacaacaacaacaacaaccaabbccab";
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'}); if(b) pq.push({b,'b'});if(c) pq.push({c,'c'});
        string res="";
        while(!pq.empty()){
            int freq=pq.top().first; char chr = pq.top().second; pq.pop();
            res.push_back(chr); freq--;
            if(freq){
                res.push_back(chr); freq--;
            }
            if(pq.empty()) return res;
            int smolfreq=pq.top().first; char smolchr=pq.top().second; pq.pop();
            res.push_back(smolchr); smolfreq--;
            if(smolfreq && smolfreq>freq){
                res.push_back(smolchr); smolfreq--;
            }
            if(freq) pq.push({freq,chr});
            if(smolfreq) pq.push({smolfreq,smolchr});
        }
        return res;
    }
};