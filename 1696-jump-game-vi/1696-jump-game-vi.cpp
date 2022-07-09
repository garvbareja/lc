class custom{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,custom> pq; pq.push({nums.back(),nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
            while(!pq.empty() && pq.top().second>i+k) pq.pop();
            int cur_score=nums[i]+pq.top().first;
            pq.push({cur_score,i});
            if(!i) return cur_score;
        }
        return nums[0];
    }
};