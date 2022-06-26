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
    
    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry=0; ListNode* sentinal=new ListNode(0);
        ListNode* prev=sentinal;
        while(l1 || l2 || carry){
            if(l1){
                carry+=l1->val;
                l1=l1->next;
            }
            if(l2){
                carry+=l2->val;
                l2=l2->next;
            }
            ListNode* newnode=new ListNode(carry%10);
            prev->next=newnode;
            prev=newnode;
            carry/=10;
        }
        return sentinal->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return rev(add(rev(l1),rev(l2)));
    }
};