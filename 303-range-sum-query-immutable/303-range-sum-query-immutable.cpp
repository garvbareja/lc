class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        int cur=0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            prefixsum.push_back(cur);
        }
    }
    
    int sumRange(int left, int right) {
        if(!left) return prefixsum[right];
        return prefixsum[right]-prefixsum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */