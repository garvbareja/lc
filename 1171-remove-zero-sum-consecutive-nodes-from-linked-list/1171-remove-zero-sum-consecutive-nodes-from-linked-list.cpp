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
                ListNode* prev = hash[sum];
                ListNode* temp = prev->next;
                prev->next=head->next;
                int temp_sum=sum;
                while(temp!=head){
                    temp_sum+=temp->val;
                    hash.erase(temp_sum);
                    temp=temp->next;
                }
            }else hash[sum]=head;
            head=head->next;
        }
        return sentinal->next;
    }
};