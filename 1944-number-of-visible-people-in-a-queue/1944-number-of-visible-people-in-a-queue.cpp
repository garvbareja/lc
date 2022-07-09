class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {
        stack<int> s; vector<int> res(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            int visible=0;
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
                visible+=1;
            }
            if(!s.empty()) visible+=1;
            res[i]=visible;
            s.push(nums[i]);
        }
        return res;
    }
};