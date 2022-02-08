class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_impact=0,chunks=0;
        for(int i=0;i<arr.size();i++){
            max_impact=max(max_impact,arr[i]);
            if(max_impact==i) chunks++;
        }
        return chunks;
    }
};