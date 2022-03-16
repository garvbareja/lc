class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s; int i=0,j=0;
        while(i<pushed.size() || j<popped.size()){
            if(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }else{
                if(i==pushed.size()) return false;
                s.push(pushed[i]);
                i++;
            }
        }
        return i==pushed.size()&&j==pushed.size();
    }
};