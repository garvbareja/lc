class custom{
public:
    bool operator()(pair<int,string>& a,pair<int,string>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hash;
        priority_queue<pair<int,string>,vector<pair<int,string>>,custom> pq;
        for(int i=0;i<words.size();i++) hash[words[i]]++;
        for(auto it=hash.begin();it!=hash.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k) pq.pop();
        }
        vector<string> res(pq.size()); int i=pq.size()-1;
        while(!pq.empty()){
            res[i--]=pq.top().second; pq.pop();
        }
        return res;
    }
};