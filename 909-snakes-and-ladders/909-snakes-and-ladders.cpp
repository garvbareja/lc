class Solution {
public:
    int n;
    int getrow(int num){
        return (n-1)-((num-1)/n);
    }
    
    int getcol(int num){
        if(n%2){
            if(getrow(num)%2){
            return (n-1)-((num-1)%n);
        }else{
            return (num-1)%n;
        }
        }
        if(getrow(num)%2){
            return (num-1)%n;
        }else{
            return (n-1)-((num-1)%n);
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board){
        unordered_set<int> hash;
        n=board.size();
        queue<int> q; q.push(1); hash.insert(1);
        int step=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int front = q.front(); q.pop();
                if(front==n*n) return step;
                int dice=1;
                while(dice<=6 && front+dice<=n*n){
                    if(board[getrow(front+dice)][getcol(front+dice)]!=-1){
                        if(!hash.count(board[getrow(front+dice)][getcol(front+dice)])){
                            q.push(board[getrow(front+dice)][getcol(front+dice)]);
                            hash.insert(board[getrow(front+dice)][getcol(front+dice)]);
                        }
                    }
                    else{
                        if(!hash.count(front+dice)){
                            hash.insert(front+dice);
                            q.push(front+dice);
                        }
                    }
                    dice++;
                }
            }
            step++;
        }
        return -1;
    }
};