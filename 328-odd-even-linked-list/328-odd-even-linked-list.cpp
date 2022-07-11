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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddhead=new ListNode(0);
        ListNode* evenhead=new ListNode(0);
        ListNode* oddprev=oddhead;
        ListNode* evenprev=evenhead;
        while(head && head->next){
            ListNode* next=head->next->next;
            evenprev->next=head->next;
            oddprev->next=head;
            oddprev=oddprev->next;
            evenprev=evenprev->next;
            oddprev->next=nullptr;
            evenprev->next=nullptr;
            head=next;
        }
        if(head){
            oddprev->next=head;
            oddprev=head;
        }
        oddprev->next=evenhead->next;
        return oddhead->next;
    }
};