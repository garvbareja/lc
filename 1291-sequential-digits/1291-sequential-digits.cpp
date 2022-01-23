class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i=1;i<=9;i++){
            q.push(i);
        }
        while(!q.empty()){
                int front=q.front(); q.pop();
                if(front>=low && front<=high) ans.push_back(front);
            if(front%10 < 9){
                int newnumber = front*10 + front%10 + 1;
                if(newnumber<=high) q.push(newnumber);
            }
        }
        return ans;
    }
};