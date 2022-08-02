class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        int m=matrix.size();
        for(int i=0;i<min(k,m);i++) pq.push({matrix[i][0],i,0});
        while(k!=1){
            int i=pq.top()[1]; int j=pq.top()[2]; pq.pop(); k-=1;
            if(j+1<matrix.size()) pq.push({matrix[i][j+1],i,j+1});
        }
        return pq.top()[0];
    }
};