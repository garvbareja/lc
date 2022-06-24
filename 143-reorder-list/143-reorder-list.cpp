/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev=nullptr;
        while(head){
            ListNode* nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow->next; slow->next=nullptr; slow=head;
        fast=rev(fast);
        ListNode* prev=new ListNode(0);
        while(slow && fast){
            ListNode* nextslow=slow->next;
            ListNode* nextfast=fast->next;
            prev->next=slow;
            slow->next=fast;
            fast->next=nullptr;
            prev=fast;
            slow=nextslow;
            fast=nextfast;
        }
        if(slow) prev->next=slow;
        if(fast) prev->next=fast;
    }
};