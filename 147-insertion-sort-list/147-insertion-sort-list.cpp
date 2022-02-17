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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* sentinal = new ListNode(-5001); ListNode* prev=sentinal;
        while(head)
        {
            ListNode* next_process = head->next;
            if(head->val>=prev->val)
            {
                prev->next=head;
                prev=head;
            }
            else
            {
                ListNode* tempprev=sentinal; ListNode* temphead=sentinal->next;
                while(temphead!=head && temphead->val<head->val){
                    tempprev=tempprev->next;
                    temphead=temphead->next;
                }
                head->next=tempprev->next;
                tempprev->next=head;
                prev->next=nullptr;
            }
            head=next_process;
        }
        return sentinal->next;
    }
};