class Solution {
public:
    bool dfs(vector<int>& arr,int i){
        if(i<0 || i>=arr.size() || arr[i]<0) return false;
        if(arr[i]==0) return true;
        int temp=arr[i];
        arr[i]=-1;
        return dfs(arr,i+temp)||dfs(arr,i-temp);
    }
    
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr,start);
    }
};