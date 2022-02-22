class Solution {
public:
    static bool cmp(string& a,string& b){
        return a+b>b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> data(nums.size());
        for(int i=0;i<nums.size();i++) data[i]=to_string(nums[i]);
        sort(data.begin(),data.end(),cmp);
        string res=""; bool flag=false;
        for(int i=0;i<data.size();i++){
            res+=data[i];
            if(!flag && stoi(data[i])!=0) flag=true;
        }
        return flag?res:"0";
    }
};