class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hash;
        for(int i=0;i<arr.size();i++){
            if(hash.count(arr[i]*2) ||(arr[i]%2==0 && hash.count(arr[i]/2))) return true;
            hash.insert(arr[i]);
        }
        return false;
    }
};