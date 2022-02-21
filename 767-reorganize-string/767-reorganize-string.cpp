class Solution {
public:
    string reorganizeString(string &s){
        vector<int> hash(26);
        for(int i=0;i<s.length();i++) hash[s[i]-'a']++;
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++) if(hash[i]) pq.push({hash[i],'a'+i});
        string res="";
        while(!pq.empty()){
            int freq=pq.top().first; char chr = pq.top().second; pq.pop();
            res.push_back(chr); freq--;
            if(pq.empty()){
                if(freq) return "";
                else return res;
            }
            int smolfreq=pq.top().first; char smolchr = pq.top().second; pq.pop();
            res.push_back(smolchr); smolfreq--;
            if(freq){
                pq.push({freq,chr});
            }
            if(smolfreq) pq.push({smolfreq,smolchr});
        }
        return res;
    }
};