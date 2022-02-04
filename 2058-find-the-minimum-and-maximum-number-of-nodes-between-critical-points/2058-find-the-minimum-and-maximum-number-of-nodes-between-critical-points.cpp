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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev=head->val; head=head->next;
        int first=-1; int mn=INT_MAX; int prev_i=-1; int i=2;
        while(head->next){
            if(prev<head->val && head->val>head->next->val || prev>head->val && head->val<head->next->val){
                if(prev_i!=-1) mn=min(mn,i-prev_i);
                prev_i=i;
                if(first==-1) first=i;
            }
            prev=head->val;
            head=head->next;
            i++;
        }
        if(mn==INT_MAX) return {-1,-1};
        return {mn,prev_i-first};
    }
};