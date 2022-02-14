class Solution {
public:
    vector<int> partitionLabels(string &s) {
        vector<int> freq(26);
        for(int i=0;i<s.length();i++) freq[s[i]-'a']++;
        vector<bool> vis(26);
        vector<int> ans;
        int seen=0,count=0;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(!vis[s[i]-'a']){
                seen++;
                vis[s[i]-'a']=true;
            }
            freq[s[i]-'a']--;
            if(!freq[s[i]-'a']) count++;
            if(count==seen){
                ans.push_back(i-j+1);
                count=0;
                seen=0;
                j=i+1;
            }
        }
        return ans;
    }
};