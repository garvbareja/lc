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
    ListNode* sentinal = new ListNode(-10000001);
    //merge two sorted lists
    ListNode* merge(ListNode* a,ListNode* b){
        if(!a) return b; if(!b) return a;
        sentinal->next=nullptr; ListNode* prev=sentinal;
        while(a || b){
            if(a&&b){
                if(a->val<b->val){
                    prev->next=a;
                    a=a->next;
                }else{
                    prev->next=b;
                    b=b->next;
                }
                prev=prev->next;
            }else if(a){
                prev->next=a; break;
            }else{
                prev->next = b; break;
            }
        }
        return sentinal->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=nullptr;
        return merge(sortList(head),sortList(temp));
    }
};