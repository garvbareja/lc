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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        ListNode* headl = nullptr;
        ListNode* taill = nullptr;
        ListNode* headr = nullptr;
        ListNode* tailr = nullptr;
        while(head){
            ListNode* nxt = head->next;
            if(head->val<x){
                if(!headl){
                    headl=head;
                    taill=head;
                }else{
                    taill->next=head;
                    taill=head;
                }
            }else{
                if(!headr){
                    headr=head;
                    tailr=head;
                }else{
                    tailr->next=head;
                    tailr=head;
                }
            }
            head->next=nullptr;
            head=nxt;
        }
        if(!headl) return headr;
        taill->next=headr;
        return headl;
    }
};