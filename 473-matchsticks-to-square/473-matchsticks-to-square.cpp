class Solution {
public:
    int sum=0;
    bool dfs(vector<int>& sticks,int i,int l,int r,int u,int d){
        if(l>sum || r>sum || u>sum || d>sum) return false;
        if(i==sticks.size()){
            if(l==sum && r==sum && u==sum && d==sum) return true;
            return false;
        }
        if(dfs(sticks,i+1,l+sticks[i],r,u,d)) return true;
        if(dfs(sticks,i+1,l,r+sticks[i],u,d)) return true;
        if(dfs(sticks,i+1,l,r,u+sticks[i],d)) return true;
        if(dfs(sticks,i+1,l,r,u,d+sticks[i])) return true;
        return false;
    }
    
    bool makesquare(vector<int>& sticks) {
        for(int i=0;i<sticks.size();i++) sum+=sticks[i];
        if(sum%4) return false;
        sum/=4;
        sort(sticks.begin(),sticks.end(),greater<int>());
        return dfs(sticks,0,0,0,0,0);
    }
};