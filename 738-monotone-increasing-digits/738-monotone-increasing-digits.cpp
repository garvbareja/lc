class Solution {
public:
    int monotoneIncreasingDigits(int n){
        string s = to_string(n);
        int i=1;
        while(i<s.length() && s[i]>=s[i-1]) i++;
        while(i<s.length() && i>0 && s[i-1]>s[i]){
            s[i-1]--;
            i--;
        }i++;
        while(i<s.length()){
            s[i]='9';
            i++;
        }
        return stoi(s);
    }
};