class Solution {
public:
    string freqAlphabets(string &s) {
        string res=""; int i=0;
        while(i<s.length()){
            if(s[i]=='1' && i+2<s.length() && s[i+2]=='#'){ res.push_back(10+s[i+1]-'1'+'a'); i+=3;}
            else if(s[i]=='2' && i+2<s.length() && s[i+2]=='#'){ res.push_back(20+s[i+1]-'1'+'a'); i+=3;}
            else{res.push_back(s[i]-'1'+'a'); i++;}
        } 
        return res;
    }
};