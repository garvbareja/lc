class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode* sentinal = new ListNode(-1);
        ListNode* prev=sentinal;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++) if(lists[i]) pq.push({lists[i]->val,lists[i]});
        while(!pq.empty()){
            ListNode* cur = pq.top().second; pq.pop();
            prev->next=cur; prev=cur;
            if(cur->next) pq.push({cur->next->val,cur->next});
        }
        return sentinal->next;
    }
};