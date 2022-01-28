class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                if(s.empty()){
                    s.push(nums[i]);
                }else{
                    if(s.top()>0){
                        while(!s.empty() && s.top()>0 && s.top()<abs(nums[i])) s.pop();
                        if(s.empty()){
                            s.push(nums[i]);
                        }else{
                            if(s.top()>0){
                                if(s.top()==abs(nums[i])) s.pop();
                            }else{
                                s.push(nums[i]);
                            }
                        }
                    }else{
                        s.push(nums[i]);
                    }
                }
            }else s.push(nums[i]);
        }
        vector<int> res(s.size()); int index=s.size()-1;
        while(!s.empty()){
            res[index--]=s.top(); s.pop();
        }
        return res;
    }
};