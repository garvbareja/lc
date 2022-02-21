class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        if(needle.length()>haystack.length()) return -1;
        int i=0,j=0;
        for(int i=0;i<=haystack.length()-needle.length();i++){
            if(haystack[i]==needle[0]){
                int j=0;
                for(;j<needle.length();j++){
                    if(haystack[i+j]!=needle[j]) break;
                }
                if(j==needle.length()) return i;
            }
        }
        return -1;
    }
};