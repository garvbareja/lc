class Solution {
public:
    string decode(string& s,int left,int right){
        string res=""; int i=left,times=0,newright,open=0;
        while(i<=right){
            if(isdigit(s[i])){
                times=times*10+(s[i]-'0');
            }else{
                if(s[i]!='[') res.push_back(s[i]);
                else{
                    newright=i+1; open=0;
                    while(s[newright]!=']' || open){
                        if(s[newright]=='[') open++;
                        if(s[newright]==']') open--;
                        newright++;

                    }
                    string temp=decode(s,i+1,newright-1);
                    while(times--) res+=temp;
                    i=newright; times=0;
                }
            }
            i++;
        }
        return res;
    }
    
    string decodeString(string s) {
        return decode(s,0,s.length()-1);
    }
};