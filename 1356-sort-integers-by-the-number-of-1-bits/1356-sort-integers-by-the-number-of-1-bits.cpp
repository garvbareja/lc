class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    int bits(int num){
        int ans=0;
        for(int i=31;i>=0;i--) if((1<<i)&num) ans++;
        return ans;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> temp(arr.size());
        for(int i=0;i<arr.size();i++) temp[i]={bits(arr[i]),arr[i]};
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<arr.size();i++) arr[i]=temp[i].second;
        return arr;
    }
};