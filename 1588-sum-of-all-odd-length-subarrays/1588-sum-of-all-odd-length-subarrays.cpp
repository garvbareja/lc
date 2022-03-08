class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0,cur=0;
        for(int i=0;i<arr.size();i++){
            cur=0;
            for(int j=i;j<arr.size();j++){
                cur+=arr[j];
                if((j-i+1)%2) ans+=cur;
            }
        }
        return ans;
    }
};