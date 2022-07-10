class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        while(i<start.length() && j<target.length()){
            while(i<start.length() && start[i]=='_') i++;
            while(j<target.length() && target[j]=='_') j++;
            
            if(i>=start.length() || j>=target.length()) return i==start.length()&&j==target.length();
            if(start[i]!=target[j]) return false;
            if(target[j]=='L'){
                if(i<j) return false;
            }else{
                if(i>j) return false;
            }
            i++; j++;
        }
        return true;
    }
};