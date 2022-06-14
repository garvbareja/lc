class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp;
        for(int i=0;i<s.length()-1;i++){
            if(s.length()%(i+1)==0){
                string dtemp="";
                temp=s.substr(0,i+1);
                int val=s.length()/(i+1);
                while(val--) dtemp+=temp;
                if(dtemp==s) return true;
            }
        }
        return false;
    }
};