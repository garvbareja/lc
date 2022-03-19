class FreqStack {
public:
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int,int> freq;
    int time = 0;
    FreqStack(){
    }
    
    void push(int val){
        freq[val]++;
        time++;
        pq.push({freq[val], {time, val} });
    }
    
    int pop(){
        auto mx = pq.top(); pq.pop();
        freq[mx.second.second]--;
        return mx.second.second;
    }
};