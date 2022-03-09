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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sentinal = new ListNode(-10001);
        ListNode* prev = sentinal;
        while(head){
            if(head->next && head->next->val==head->val){
                prev->next=nullptr;
                while(head->next && head->next->val==head->val) head=head->next;
            }else{
                prev->next=head;
                prev=head;
            }
            if(head) head=head->next;
        }
        return sentinal->next;
    }
};