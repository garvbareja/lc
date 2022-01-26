class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(n){ fast = fast->next; n--; }
        if(!fast){
            head = head->next;
            return head;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
