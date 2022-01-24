class Solution {
public:
    bool detectCapitalUse(string word) {
        bool small = false;
        bool up = false;
        if(!isupper(word[0])) small = true;
        for(int i=1;i<word.length();i++){
            if(isupper(word[i])){
                if(small) return false;
                up = true;
            }else{
                if(up) return false;
                small=true;
            }
        }
        return true;
    }
};