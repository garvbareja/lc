class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* faster = head;
        while(--k){
            slow = slow->next;
        }
        faster = slow;
        while(faster->next){
            faster = faster->next;
            fast = fast->next;
        }
        swap(fast->val,slow->val);
        return head;
    }
};