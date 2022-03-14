class Solution {
public:
    bool dfs(string &s,int i,long long prev){
        if(i==s.length()) return true;
        if(prev==-1){
            prev=0;
            for(;i<s.length()-1 && prev<=LONG_MAX/10;i++){
                prev=prev*10+(s[i]-'0');
                if(dfs(s,i+1,prev)) return true;
            }
        }else{
            long long cur=0;
            int counter=0;
            for(;i<s.length() && cur<=LONG_MAX/10;i++){
                cur=cur*10+(s[i]-'0');
                if(cur+1==prev && dfs(s,i+1,cur)) return true;
                counter++;
            }
        }
        return false;
    }
    
    bool splitString(string &s) {
        return dfs(s,0,-1);
    }
};