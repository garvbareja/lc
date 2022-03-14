class Solution {
public:
    string simplifyPath(string &path) {
        stack<string> s; string res="",temp="";
        int i=0; if(path.back()!='/') path.push_back('/');
        while(i<path.length()){
            if(path[i]=='/'){
                if(temp==".." && !s.empty()) s.pop();
                else if(temp.length() && temp!="." && temp!="..") s.push(temp);
                temp="";
            }else temp.push_back(path[i]);
            i++;
        }
        while(!s.empty()){
            res="/"+s.top()+res;
            s.pop();
        }
        return res.empty()?"/":res;
    }
};