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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* sentinal = new ListNode(-10001);
        ListNode* prev = sentinal; int carry=0;
        while(l1 || l2 || carry){
            int digit=carry;
            if(l1) digit+=l1->val;
            if(l2) digit+=l2->val;
            ListNode* newnode = new ListNode(digit%10);
            prev->next=newnode;
            prev=prev->next;
            carry=digit/10;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return sentinal->next;
    }
};