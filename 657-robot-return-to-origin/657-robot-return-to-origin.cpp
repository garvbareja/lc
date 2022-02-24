class Solution {
public:
    bool judgeCircle(string &moves) {
        int i=0,j=0;
        for(int z=0;z<moves.length();z++){
            if(moves[z]=='U') j++;
            else if(moves[z]=='D') j--;
            else if(moves[z]=='R') i++;
            else i--;
        }
        return i==0&&j==0;
    }
};