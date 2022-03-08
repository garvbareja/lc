class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next && slow!=fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        return fast==slow?true:false;
    }
};