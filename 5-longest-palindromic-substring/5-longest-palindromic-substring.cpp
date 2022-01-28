class Solution {
public:
    string longestPalindrome(string s) {
        int len=0,start=0;
        for(int i=0;i<s.length();i++){
            int left=i,right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if(right-left+1 > len){
                    len=right-left+1;
                    start=left;
                }
                left--;right++;
            }
            left=i;right=i+1;
            while(left>=0 && right<s.length()&&s[left]==s[right]){
                if(right-left+1>len){
                    len=right-left+1;
                    start=left;
                }
                left--;right++;
            }
        }
        return s.substr(start,len);
    }
};