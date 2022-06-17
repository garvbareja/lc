class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        for(int i=0;i<s.length();i++) hash[s[i]]++;
        bool flag=true; int res=0;
        for(auto it=hash.begin();it!=hash.end();it++){
            if(it->second%2){
                if(flag){
                    res+=it->second;
                    flag=false;
                }else{
                    res+=it->second-1;
                }
            }else{
                res+=it->second;
            }
        }
        return res;
    }
};