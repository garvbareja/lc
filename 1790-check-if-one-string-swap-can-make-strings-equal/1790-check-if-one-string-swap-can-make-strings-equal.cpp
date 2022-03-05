class Solution {
public:
    bool areAlmostEqual(string &s1, string &s2) {
        bool flag=true,dflag=true; char a,b;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(flag){
                    a=s1[i]; b=s2[i];
                    flag=false;
                }else{
                    if(dflag){
                        if(a!=s2[i] || b!=s1[i]) return false;
                        dflag=false;
                    }else return false;
                }
            }
        }
        return (flag&&dflag) || (!flag&&!dflag);
    }
};