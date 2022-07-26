class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        priority_queue<int> pq; queue<pair<int,int>> q;
        for(int i=0;i<tasks.size();i++) freq[tasks[i]-'A']+=1;
        for(int i=0;i<26;i++) if(freq[i]) pq.push(freq[i]);
        int curtime=0;
        while(!q.empty() || !pq.empty()){
            if(!pq.empty()){
                int cur_freq=pq.top(); pq.pop();
                if(cur_freq>1) q.push({cur_freq-1,curtime+n});
            }
            while(!q.empty() && curtime==q.front().second){
                pq.push(q.front().first); q.pop();
            }
            curtime+=1;
        }
        return curtime;
    }
};