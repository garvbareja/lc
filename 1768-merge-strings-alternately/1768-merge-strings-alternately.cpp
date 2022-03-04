class Solution {
public:
    string mergeAlternately(string &s1, string &s2) {
        int i=0,j=0;
        string res="";
        while(i<s1.length() || j<s2.length()){
            if(i<s1.length()) res.push_back(s1[i++]);
            if(j<s2.length()) res.push_back(s2[j++]);
        }
        return res;
    }
};