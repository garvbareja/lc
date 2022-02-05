class Solution {
public:
    unordered_map<int,int> hash;
    vector<vector<int>> ans;
    vector<int> temp; int n;
    void dfs(){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(auto it=hash.begin();it!=hash.end();it++){
            if(it->second){
                it->second-=1;
                temp.push_back(it->first);
                dfs();
                temp.pop_back();
                it->second+=1;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<nums.size();i++) hash[nums[i]]++;
        dfs();
        return ans;
    }
};