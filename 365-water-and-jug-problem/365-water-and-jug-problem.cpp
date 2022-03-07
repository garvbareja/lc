class Solution {
public:
    int t; long long numy;
    unordered_set<long long int> hash;
    queue<pair<int,int>> q;
    long long customhash(long long a,long long b){
        return a*numy+b;
    }
    
    bool add(int a,int b){
        if(!hash.count(customhash(a,b))){
            if(a==t || b==t || a+b==t) return true;
            q.push({a,b});
            hash.insert(customhash(a,b));
        }
        return false;
    }
    
    bool canMeasureWater(int x, int y, int target){
        if(target==0) return true;
        
        t=target;
        if(x%2==0 && y%2==0 && t%2!=0) return false;
        numy=y+1; q.push({0,0}); hash.insert(0);
        while(!q.empty()){
            int a=q.front().first; int b=q.front().second; q.pop();
            if(add(0,b)) return true;
            if(add(a,0)) return true;
            if(add(x,b)) return true;
            if(add(a,y)) return true;
            if(add(a+min(b,x-a),b-min(b,x-a))) return true;
            if(add(a-min(a,y-b),b+min(a,y-b))) return true;
        }
        return false;
    }
};