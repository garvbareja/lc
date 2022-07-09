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
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast = slow->next;
        slow->next=nullptr;
        fast=rev(fast);
        while(head && fast){
            if(head->val!=fast->val) return false;
            cout<<head->val<<" "<<fast->val<<endl;
            head=head->next;
            fast=fast->next;
        }
        return true;
    }
};