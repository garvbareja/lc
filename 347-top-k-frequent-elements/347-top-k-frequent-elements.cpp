class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it=hash.begin();it!=hash.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans(k);
        int i=k-1;
        while(!pq.empty()){
            ans[i]=pq.top().second;
            i--; pq.pop();
        }
        return ans;
    }
};