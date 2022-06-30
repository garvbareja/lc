class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> hash; string res=""; string temp="";
        for(int i=0;i<knowledge.size();i++) hash[knowledge[i][0]]=knowledge[i][1];
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){int j=i+1;
                while(s[i]!=')') i++;
                temp=s.substr(j,i-j);
                if(hash.count(temp)) res+=hash[temp];
                else res.push_back('?');
            }else res.push_back(s[i]);
        }
        return res;
    }
};