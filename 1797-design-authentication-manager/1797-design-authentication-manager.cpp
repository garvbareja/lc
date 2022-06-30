class AuthenticationManager {
public:
    unordered_map<string,int> hash;
    int time;
    AuthenticationManager(int timeToLive) {
        time=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        hash[tokenId]=currentTime+time;
    }
    
    void renew(string tokenId, int currentTime) {
        if(hash.count(tokenId)){
            if(hash[tokenId]>currentTime) hash[tokenId]=currentTime+time;
            else hash.erase(tokenId);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res=0;
        for(auto it=hash.begin();it!=hash.end();it++){
            if(it->second>currentTime) res++;
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */