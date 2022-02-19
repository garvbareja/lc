class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                pq.push(nums[i]*2);
                mn=min(mn,nums[i]*2);
            }else{
                pq.push(nums[i]);
                mn=min(mn,nums[i]);
            }
        }
        int ans=INT_MAX;
        while(!(pq.top()%2)){
            int top = pq.top(); pq.pop();
            ans=min(ans,top-mn);
            mn=min(mn,top/2);
            pq.push(top/2);
        }
        ans=min(ans,pq.top()-mn);
        return ans;
    }
};