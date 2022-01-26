class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> hash(127);
        int i=0,j=0,ans=0;
        while(i<s.length()){
            if(hash[s[i]]){
                while(s[j]!=s[i]){
                    hash[s[j]]=false;
                    j++;
                }
                j++;
            }else hash[s[i]]=true;
            i++;
            ans=max(ans,i-j);
        }
        return ans;
    }
};