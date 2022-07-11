class Solution {
public:
    string convert(string &s, int n) {
        vector<string> temp(n);
        bool flag=true; int i=0;
        while(i<s.length()){
            if(flag){
                for(int j=0;j<n&&i<s.length();j++,i++) temp[j].push_back(s[i]);
                flag=false;
            }else{
                for(int j=n-2;j>0&&i<s.length();j--,i++) temp[j].push_back(s[i]);
                flag=true;
            }
        }
        string res="";
        for(int i=0;i<temp.size();i++) res+=temp[i];
        return res;
    }
};