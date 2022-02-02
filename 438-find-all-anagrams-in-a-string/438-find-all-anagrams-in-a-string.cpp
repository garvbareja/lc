class Solution {
public:
    vector<int> findAnagrams(string& s, string& p) {
        vector<int> ans,hash(26); int count=0;
        for(int i=0;i<p.length();i++){
            if(!hash[p[i]-'a']) count++;
            hash[p[i]-'a']++;
        }
        int i=0,j=0;
        while(i<s.length()){
            if(hash[s[i]-'a']){
                hash[s[i]-'a']--;
                if(!hash[s[i]-'a']) count--;
                if(!count){
                    ans.push_back(j);
                    hash[s[j]-'a']++; count++;
                    j++;
                }
            }else{
                while(s[j]!=s[i]){
                    if(!hash[s[j]-'a']) count++;
                    hash[s[j]-'a']++;
                    j++;
                }j++;
            }
            i++;
        }
        return ans;
    }
};