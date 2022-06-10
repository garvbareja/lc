class Solution {
public:
    bool isPalindrome(string &s) {
        int low=0,high=s.length()-1;
        while(low<high){
            while(low<s.length() && !isalpha(s[low]) && !isdigit(s[low])) low++;
                        if(low>=high) break; 

            while(high>=0 && !isalpha(s[high]) && !isdigit(s[high])) high--;
            if(low>=high) break; 
            if(tolower(s[low])!=tolower(s[high])) return false;
            low++; high--;
        }
        return true;
    }
};