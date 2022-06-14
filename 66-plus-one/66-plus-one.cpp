class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1,carry=1;
        while(i>=0 && carry){
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
            i--;
        }
        if(carry) digits.insert(digits.begin(),1);
        return digits;
    }
};