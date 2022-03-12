class Solution {
public:
    static bool cmp(int& a,int& b){
        int counta=0,countb=0;
        for(int i=31;i>=0;i--){
            if((1<<i)&a) counta+=1;
            if((1<<i)&b) countb+=1;
        }
        if(counta==countb) return a<b;
        return counta<countb;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};