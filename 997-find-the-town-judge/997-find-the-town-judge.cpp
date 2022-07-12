class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        for(int i=0;i<trust.size();i++){
            indegree[trust[i][1]]+=1;
            indegree[trust[i][0]]-=1;
        }
        for(int i=1;i<=n;i++) if(indegree[i]==n-1) return i;
        return -1;
    }
};