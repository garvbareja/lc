class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int> hash(28);
        for(int i=0;i<s1.length();i++) hash[s1[i]-'a']++;
        int i=0,j=0;
        while(i<s2.length()){
            if(hash[s2[i]-'a']){
                hash[s2[i]-'a']--;
                if(i-j+1==s1.length()){
                    return true;
                }
            }else{
                while(s2[j]!=s2[i]){
                    hash[s2[j]-'a']++;
                    j++;
                }j++;
            }
            i++;
        }
        return false;
    }
};