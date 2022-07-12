class Solution {
public:
    string replaceWords(vector<string>& dic, string &s) {
        unordered_set<string> hash; string temp="",res=""; bool flag=true;
        for(int i=0;i<dic.size();i++) hash.insert(dic[i]);
        for(int i=0;i<s.length();i++){
            flag=true; temp="";
            while(i<s.length() && s[i]!=' '){
                if(flag){
                    temp.push_back(s[i]);
                    if(hash.count(temp)) flag=false;;
                }i++;
            }
            if(res.length()) res.push_back(' ');
            res+=temp;
        }
        return res;
    }
};