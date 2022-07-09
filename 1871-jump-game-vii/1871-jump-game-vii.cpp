class Solution {
public:
    bool canReach(string &s, int minjump, int maxjump) {
        if(s[0]=='1' || s.back()=='1') return false;
        int n=s.length(); queue<int> q; q.push(0); int farthest=0;
        while(!q.empty()){
            int cur=q.front(); q.pop();
            int from=max(cur+minjump,farthest+1);
            int till=min(cur+maxjump,n-1);
            for(int i=from;i<=till;i++){
                if(s[i]=='0'){
                    q.push(i);
                    if(i==n-1) return true;
                }
                farthest=till;
            }
        }
        return false;
    }
};