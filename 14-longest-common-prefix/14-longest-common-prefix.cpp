class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int index=0;
        while(true){
            for(int i=0;i<strs.size();i++){
                if(index>=strs[i].length()) return res;
                if(i>0) if(strs[i][index]!=strs[i-1][index]) return res;
            }
            res.push_back(strs[0][index]);
            index++;
        }
        return res;
    }
};