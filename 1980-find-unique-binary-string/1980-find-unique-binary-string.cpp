class Solution {
public:
    int n;
    string temp="";
    unordered_set<string> hash;
    bool dfs(){
        if(temp.length()==n){
            if(hash.count(temp)) return false;
            return true;
        }
        temp.push_back('1'); if(dfs()) return true; temp.pop_back();
        temp.push_back('0'); if(dfs()) return true; temp.pop_back();
        return false;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        for(int i=0;i<nums.size();i++) hash.insert(nums[i]);
        n=nums.size();
        dfs();
        return temp;
    }
};