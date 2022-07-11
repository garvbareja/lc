class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> hash; bool flag=true; double res=0; int freq;
        string temp="";
        for(int i=0;i<words.size();i++) hash[words[i]]+=1;
        for(auto it=hash.begin();it!=hash.end();it++){
            if(it->first[1]==it->first[0]){
                if(it->second%2){
                    res+=it->second-1; it->second=1;
                    if(flag){
                        res+=1; it->second=0;
                        flag=false;
                    }
                }else res+=it->second; it->second=0;
            }else{
                temp=""; temp.push_back(it->first[1]); temp.push_back(it->first[0]);
                if(hash.count(temp) && hash[temp]){
                    freq=min(hash[temp],it->second);
                    res+=freq; res+=freq; hash[temp]-=freq; it->second-=freq;
                }
            }
        }
        return res*2;
    }
};