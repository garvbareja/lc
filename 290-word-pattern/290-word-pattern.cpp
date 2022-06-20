class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> char_to_string; unordered_map<string,char> string_to_char;
        int i=0,j=0; string temp; int index=0;
        while(i<s.length() && index<pattern.length()){
            while(i<s.length() && s[i]!=' ') i++;
            temp=s.substr(j,i-j);
            if(char_to_string.count(pattern[index]) && char_to_string[pattern[index]]!=temp) return false;
            if(string_to_char.count(temp) && string_to_char[temp]!=pattern[index]) return false;
            string_to_char[temp]=pattern[index];
            char_to_string[pattern[index]]=temp;
            i++; index++; j=i;
        }
        return index==pattern.size() && i>=s.length();
    }
};