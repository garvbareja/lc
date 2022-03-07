class RandomizedSet {
public:
    unordered_map<int,int> hash;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.count(val)) return false;
        nums.push_back(val);
        hash[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!hash.count(val)) return false;
        int index=hash[val];
        swap(nums[index],nums[nums.size()-1]);
        hash[nums[index]]=index;
        hash.erase(nums.back());
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */