class cmp{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.first>b.first;
    }
};

class Twitter {
public:
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,unordered_map<int,int>> tweets;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId][tweetId]=time;
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        if(following.count(userId))
        for(auto it=following[userId].begin();it!=following[userId].end();it++){
            for(auto i=tweets[*it].begin();i!=tweets[*it].end();i++){
                pq.push({i->second,i->first});
                if(pq.size()>10) pq.pop();
            }
        }
        if(tweets.count(userId))
            for(auto i=tweets[userId].begin();i!=tweets[userId].end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>10) pq.pop();
        }
        
        vector<int> ans(pq.size());
        int indx=pq.size()-1;
        while(!pq.empty()){
            ans[indx]=pq.top().second; indx--;
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.count(followerId) && following[followerId].count(followeeId)) following[followerId].erase(followeeId);
    }
};