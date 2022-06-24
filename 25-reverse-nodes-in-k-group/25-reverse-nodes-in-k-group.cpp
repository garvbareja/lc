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
    pair<ListNode*,ListNode*> rev(ListNode* head){
        ListNode* tail=head;
        ListNode* prev=nullptr;
        while(head){
            ListNode* enxt=head->next;
            head->next=prev;
            prev=head;
            head=enxt;
        }
        return {prev,tail};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sentinal=new ListNode(0);
        ListNode* prev=sentinal;
        while(head){
            int temp=k;
            ListNode* cur=head;
            while(head && temp!=1){
                head=head->next;
                temp--;
            }
            if(head){
                ListNode* nextprocess=head->next;
                head->next=nullptr;
                pair<ListNode*,ListNode*> res=rev(cur);
                prev->next=res.first;
                prev=res.second;
                head=nextprocess;
            }else prev->next=cur;
        }
        return sentinal->next;
    }
};