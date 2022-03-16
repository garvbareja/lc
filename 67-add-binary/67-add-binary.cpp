class Solution {
public:
    string addBinary(string &a, string &b) {
        string res=""; int carry=0,i=a.length()-1,j=b.length()-1;
        while(i>=0 || j>=0 || carry){
            if(i>=0) carry+=a[i]-'0';
            if(j>=0) carry+=b[j]-'0';
            if(carry==3 || carry==1){
                res.push_back('1');
                if(carry==3) carry=1;
                else carry=0;
            }else{
                res.push_back('0');
                if(carry) carry=1;
                else carry=0;
            }i--; j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};