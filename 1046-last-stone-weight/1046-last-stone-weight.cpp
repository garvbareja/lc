class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int x,y;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(!pq.empty() && pq.size()!=1){
            y = pq.top();
            pq.pop();
            x=pq.top();
            pq.pop();
            if(y>x) pq.push(y-x);
        }
        if(pq.size()==1) return pq.top();
        return 0;
    }
};