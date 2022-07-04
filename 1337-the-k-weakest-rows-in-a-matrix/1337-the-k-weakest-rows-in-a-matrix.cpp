class custom{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
};

class Solution {
public:
    int soldiers(vector<int>& nums){
        int low=0,high=nums.size()-1,res=-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]){
                res=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return res+1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,custom> pq;
        vector<int> res;
        for(int i=0;i<mat.size();i++){
            pq.push({soldiers(mat[i]),i});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};