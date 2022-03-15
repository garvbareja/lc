class LockingTree {
public:
    vector<int> p;
    vector<int> status;
    unordered_map<int,vector<int>> child;
    LockingTree(vector<int>& parent){
        p=parent;
        for(int i=1;i<parent.size();i++){
            child[parent[i]].push_back(i);
        }
        status.resize(parent.size());
    }
    
    bool lock(int num, int user) {
        if(status[num] || status[num]==user) return false;
        status[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!status[num] || status[num]!=user) return false;
        status[num]=0;
        return true;
    }
    //nolockedchild
    bool onelockedchild(int num){
        if(!child.count(num)){
            if(status[num]) return true;
            return false;
        }
        if(status[num]) return true;
        for(int i=0;i<child[num].size();i++){
            if(onelockedchild(child[num][i])) return true;
        }
        return false;
    }
    
    //anylockedparent
    bool anylockedparent(int num){
        while(num!=-1){
            if(status[num]) return true;
            num=p[num];
        }
        return false;
    }
    
    //unlockchildren: unlocks all the children of the current node
    void unlockchildren(int num){
        if(!child.count(num)) return;
        status[num]=0;
        for(int i=0;i<child[num].size();i++){
            status[child[num][i]]=0;
            unlockchildren(child[num][i]);
        }
    }
    
    bool upgrade(int num, int user){
        if(status[num] || !onelockedchild(num) || anylockedparent(num)) return false;
        unlockchildren(num);
        status[num]=user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */