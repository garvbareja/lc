class MyQueue {
public:
    stack<int> q;
    stack<int> to_q;
    MyQueue() {
        
    }
    void enqueue(){
        while(!to_q.empty()){
            q.push(to_q.top());
            to_q.pop();
        }
    }
    
    void push(int x) {
        to_q.push(x);
    }
    
    int pop() {
        if(q.empty()) enqueue();
        int front=q.top(); q.pop();
        return front;
    }
    
    int peek() {
        if(q.empty()) enqueue();
        return q.top();
    }
    
    bool empty() {
        return q.empty()&&to_q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */