class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<pair<int,vector<int>>> hash; int sum=0;
        for(int i=0;i<mat.size();i++) sum+=mat[i][0];
        if(k==1) return sum;
        hash.insert({sum,vector<int>(mat.size())});
        while(k>1){
            auto itr = hash.begin();
            pair<int,vector<int>> cur=(*itr);
            hash.erase(itr);
            for(int i=0;i<cur.second.size();i++){
                if(cur.second[i]+1<mat[i].size()){
                    cur.first+=mat[i][cur.second[i]+1]-mat[i][cur.second[i]];
                    cur.second[i]+=1;
                    hash.insert(cur);
                    cur.second[i]-=1;
                    cur.first+=mat[i][cur.second[i]]-mat[i][cur.second[i]+1];
                }
            }
            k--;
        }
        auto itr=hash.begin();
        return (*itr).first;
    }
};