class Solution {
public:
    string convertToTitle(int num) {
        string res="";
        while(num){
            char chr = ((num-1)%26)+'A';
            res.push_back(chr);
            num-=1; num/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};