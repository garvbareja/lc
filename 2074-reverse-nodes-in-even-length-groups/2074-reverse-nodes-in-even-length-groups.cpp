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
    pair<ListNode*,ListNode*> reverse(ListNode* head,int k){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(head && k--){
            ListNode* nxt = head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return {prev,temp};
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head){
        ListNode* res = head;
        int curlen=1; head=head->next;
        ListNode* prev = res;
        while(head){
            int nextlen=curlen+1;
            ListNode* newprev=nullptr;
            while(head && nextlen){
                newprev=head;
                head=head->next;
                nextlen--;
            }
            if(nextlen%2 && !(curlen%2) || !(nextlen%2) && curlen%2){
                pair<ListNode*,ListNode*> rev = reverse(prev->next,curlen+1);
                prev->next=rev.first;
                rev.second->next=head;
                prev=rev.second;
            }else{
                prev=newprev;
            }
            curlen++;
        }
        return res;
    }
};