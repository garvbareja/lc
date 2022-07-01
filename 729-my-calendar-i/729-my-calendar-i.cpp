class MyCalendar {
public:
    vector<vector<int>> nums;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<nums.size();i++){
            if(start<nums[i][1] && nums[i][0]<end) return false;
        }
        nums.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */