class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        string temp; unordered_set<string> hash; vector<string> res; unordered_set<string> dhash;
        for(int i=0;i<n-9;i++){
            temp=s.substr(i,10);
            if(hash.count(temp)){
                if(!dhash.count(temp)){
                    res.push_back(temp);
                    dhash.insert(temp);
                }
            }
            else hash.insert(temp);
        }
        return res;
    }
};