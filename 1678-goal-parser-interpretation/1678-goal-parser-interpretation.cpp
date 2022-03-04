class Solution {
public:
    string interpret(string &command) {
        string res=""; int i=0;
        while(i<command.size()){
            if(command[i]=='G'){
                res.push_back('G');
            }else{
                i++;
                if(command[i]==')'){
                    res.push_back('o');
                }else{
                    res.push_back('a');
                    res.push_back('l');
                    i+=2;
                }
            }
            i++;
        }
        return res;
    }
};