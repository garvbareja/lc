class MyCircularQueue {
public:
    int* arr; int front,rear,size,cap;
    MyCircularQueue(int k) {
        arr=new int[k];
        front=-1; rear=-1;
        size=0; cap=k;
    }
    
    bool enQueue(int value) {
        if(size==cap) return false;
        if(front==-1){
            rear=0; front=0;
        }else rear=(rear+1)%cap;
        arr[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(!size) return false;
        front=(front+1)%cap;
        size--; return true;
    }
    
    int Front() {
        if(!size) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(!size) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */