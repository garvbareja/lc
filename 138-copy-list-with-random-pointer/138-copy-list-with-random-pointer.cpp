/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* ok) {
        if(!ok) return nullptr;
        Node* head=ok;
        while(head){
            Node* newnode = new Node(head->val);
            newnode->next=head->next;
            head->next=newnode;
            head=newnode->next;
        }
        Node* ans=ok->next;
        head=ok;
        while(head){
            if(head->random) head->next->random=head->random->next;
            head=head->next->next;
        }
        head=ok;
        while(head){
            Node* nxt=head->next->next;
            if(nxt) head->next->next=nxt->next;
            head->next=nxt;
            head=nxt;
        }
        return ans;
    }
};