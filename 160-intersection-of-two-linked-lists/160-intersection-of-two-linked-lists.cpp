/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *aa, ListNode *bb) {
        ListNode* a=aa; ListNode* b=bb;
        while(a!=b){
            a=a->next;
            b=b->next;
            if(!a&&!b) return nullptr;
            if(!a) a=bb;
            if(!b) b=aa;
        }
        return a;
    }
};