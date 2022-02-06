class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp); int mxlen=0;
        int cur_end=-1001;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0]>cur_end){
                mxlen++;
                cur_end=pairs[i][1];
            }
        }
        return mxlen;
    }
};