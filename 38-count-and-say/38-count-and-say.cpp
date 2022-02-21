class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string say = countAndSay(n-1);
        string res=""; int i=0;
        while(i<say.length()){
            int count=0,j=i;
            while(i<say.length() && say[i]==say[j]){
                count++; i++;
            }
            res+=to_string(count);
            res.push_back(say[j]);
        }
        return res;
    }
};