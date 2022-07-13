class Solution {
public:
    bool dfs(vector<vector<int>>& room,unordered_set<int>& keys,int v){
        keys.insert(v);
        if(keys.size()==room.size()) return true;
        for(int i=0;i<room[v].size();i++){
            if(!keys.count(room[v][i])){
                if(dfs(room,keys,room[v][i])) return true;
            }
        }
        return false;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        return dfs(rooms,keys,0);
    }
};