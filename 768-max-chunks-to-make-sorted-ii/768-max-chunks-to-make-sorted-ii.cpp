class Solution {
public:
    static bool custom(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    
    int maxChunksToSorted(vector<int>& arr) {
        map<pair<int,int>,int> hash;
        vector<pair<int,int>> temp(arr.size());
        for(int i=0;i<arr.size();i++){
            temp[i]={arr[i],i};
        }
        sort(temp.begin(),temp.end(),custom);
        for(int i=0;i<temp.size();i++){
            hash[temp[i]]=i;
        }
        int max_impact=0;
        int chunks=0;
        for(int i=0;i<arr.size();i++){
            max_impact=max(max_impact,hash[{arr[i],i}]);
            if(max_impact==i) chunks++;
        }
        return chunks;
    }
};