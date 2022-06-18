// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1));
//         vector<int> prev(text2.length()+1); vector<int> cur(text1.length()+1);
//         for(int i=0;i<=text1.size();i++){
//             for(int j=0;j<=text2.size();j++){
//                 if(!i || !j) dp[i][j]=0;
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                     if(text1[i-1]==text2[j-1]) dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
//                 }
//             }
//         }
//         return dp[text1.length()][text2.length()];
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.length()+1); vector<int> cur(text2.length()+1);
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                    cur[j]=max(prev[j],cur[j-1]);
                    if(text1[i-1]==text2[j-1]) cur[j]=max(cur[j],1+prev[j-1]);
            }
            prev=cur;
        }
        return cur[text2.length()];
    }
};
