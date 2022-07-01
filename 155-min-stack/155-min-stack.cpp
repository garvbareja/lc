class MinStack {
public:
    stack<int> p;
    stack<int> q;
    MinStack() {
        
    }
    
    void push(int val) {
        p.push(val);
        if(!q.size() || q.top()>=val) q.push(val);
    }
    
    void pop() {
        if(p.top()==q.top()) q.pop();
        p.pop();
    }
    
    int top() {
        return p.top();
    }
    
    int getMin() {
        return q.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */