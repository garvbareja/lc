class MyLinkedList {
public:
    ListNode* head;
    int size;
    MyLinkedList() {
        head = new ListNode(0);
        size=0;
    }
    
    ListNode* travel(int index){
        ListNode* temp=head;
        while(index--) temp=temp->next;
        return temp;
    }
    
    int get(int index) {
        if(index>=size) return -1;
        ListNode* temp=travel(index);
        return temp->next->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        ListNode* prev=travel(index);
        ListNode* newnode=new ListNode(val);
        newnode->next=prev->next;
        prev->next=newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size) return;
        ListNode* prev=travel(index);
        ListNode* todelete=prev->next;
        prev->next=prev->next->next;
        delete(todelete);
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */