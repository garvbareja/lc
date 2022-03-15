class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!hash.count(key)) return "";
        if(hash[key].back().second<=timestamp) return hash[key].back().first;
        int low=0,high=hash[key].size(); int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(hash[key][mid].second==timestamp) return hash[key][mid].first;
            if(hash[key][mid].second<timestamp){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        if(ans==-1) return "";
        return hash[key][ans].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */