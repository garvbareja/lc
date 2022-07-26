class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hash;
        for(auto i:t) hash[i] += 1;
        int count = hash.size();
        int i=0;
        int j=0;
        string ans = "";
        while(i<s.length()){
            if(hash.count(s[i])){
                hash[s[i]] -= 1;
                if(!hash[s[i]]) count--;
            }
            if(!count){
                if(ans.empty()) ans = s.substr(j,i-j+1);
                if(i-j+1 < ans.length()) ans = s.substr(j,i-j+1);
                while(!hash.count(s[j]) || hash[s[j]] < 0){
                    if(hash.count(s[j]) && hash[s[j]] < 0){
                        hash[s[j]] ++;
                        if(hash[s[j]] > 0) count++;
                    }
                    j++;
                    if(i-j+1 < ans.length()) ans = s.substr(j,i-j+1);
                }
            }
            i++;
        }
        return ans;
    }
};