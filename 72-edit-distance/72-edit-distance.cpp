class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> prev(word2.length()+1),cur(word2.length()+1);
        for(int i=0;i<=word2.length();i++) prev[i]=i;
        for(int i=1;i<=word1.length();i++){
            cur[0]=i;
            for(int j=1;j<=word2.length();j++){
                if(word1[i-1]==word2[j-1]) cur[j]=prev[j-1];
                else cur[j]=1+min(min(prev[j],cur[j-1]),prev[j-1]);
            }
            prev=cur;
        }
        return prev[word2.length()];
    }
};