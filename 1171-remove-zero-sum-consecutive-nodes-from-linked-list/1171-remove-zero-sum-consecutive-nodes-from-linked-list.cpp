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
    ListNode* removeZeroSumSublists(ListNode* head){
        unordered_map<int,ListNode*> hash;
        ListNode* sentinal = new ListNode(0,head);
        hash[0]=sentinal;
        int sum=0;
        while(head){
            sum+=head->val;
            if(hash.count(sum)){
                ListNode* temp = hash[sum]->next;
                hash[sum]->next=head->next;
                while(temp!=head){
                    sum+=temp->val;
                    hash.erase(sum);
                    temp=temp->next;
                }sum+=head->val;
            }else hash[sum]=head;
            head=head->next;
        }
        return sentinal->next;
    }
};