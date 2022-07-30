class Solution {
public:
    void init(vector<int>& freq){
        for(int i=0;i<freq.size();i++) freq[i]=0;
    }
    
    void calc_freq(vector<int>& freq,string &cur){
        for(int i=0;i<cur.length();i++) freq[cur[i]-'a']+=1;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26),max_freq(26); vector<string> res; bool flag;
        for(int i=0;i<words2.size();i++){
            init(freq); calc_freq(freq,words2[i]);
            for(int i=0;i<26;i++) max_freq[i]=max(max_freq[i],freq[i]);
        }
        for(int i=0;i<words1.size();i++){
            init(freq); calc_freq(freq,words1[i]);
            flag=true;
            for(int j=0;j<26 && flag;j++){
                if(max_freq[j]>freq[j]) flag=false;
            }
            if(flag) res.push_back(words1[i]);
        }
        return res;
        
    }
};