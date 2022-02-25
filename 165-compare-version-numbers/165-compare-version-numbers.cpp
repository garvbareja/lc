class Solution {
public:
    int compareVersion(string &v1, string &v2) {
        int i=0,j=0;
        while(i<v1.length() || j<v2.length()){
            int val1=0,val2=0;
            while(i<v1.length() && isdigit(v1[i])){val1=val1*10 +(v1[i]-'0'); i++;}
            while(j<v2.length() && isdigit(v2[j])) { val2=val2*10 + (v2[j]-'0'); j++;}
            if(val1<val2) return -1;
            else if(val1>val2) return 1;
            i++; j++;
        }
        if(i>=v1.length() && j>=v2.length()) return 0;
        if(i<v1.length()) return -1;
        return 1;
    }
};