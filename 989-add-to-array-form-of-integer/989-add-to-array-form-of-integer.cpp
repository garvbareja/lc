class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0; vector<int> ans;
        for(int i=num.size()-1;k||i>=0||carry;i--){
            carry+=k%10; if(i>=0) carry+=num[i];
            ans.push_back(carry%10);
            carry/=10; k/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};