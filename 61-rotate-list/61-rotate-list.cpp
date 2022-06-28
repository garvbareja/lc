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
    int calclen(ListNode* head){
        int len=0;
        while(head){
            head=head->next;
            len++;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        int len=calclen(head);
        k%=len;
        if(!k) return head;
        ListNode* slow=head; ListNode* fast=head;
        while(k--) fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* newhead=slow->next;
        slow->next=nullptr;
        fast->next=head;
        return newhead;
    }
};