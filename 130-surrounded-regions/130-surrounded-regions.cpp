class Solution {
public:
    void dfs(vector<vector<char>>& nums,int i,int j){
        if(i<0 || i==nums.size() || j<0 || j==nums[i].size() || nums[i][j]!='O') return;
        nums[i][j]='T';
        dfs(nums,i+1,j);
        dfs(nums,i-1,j);
        dfs(nums,i,j+1);
        dfs(nums,i,j-1);
    }
    
    void boundry(vector<vector<char>>& nums){
        for(int i=0;i<nums[0].size();i++) if(nums[0][i]=='O') dfs(nums,0,i);
        for(int i=0;i<nums[0].size();i++) if(nums[nums.size()-1][i]=='O') dfs(nums,nums.size()-1,i);
        for(int i=0;i<nums.size();i++) if(nums[i][0]=='O') dfs(nums,i,0);
        for(int i=0;i<nums.size();i++) if(nums[i][nums[i].size()-1]=='O') dfs(nums,i,nums[i].size()-1);
    }
    
    void solve(vector<vector<char>>& nums) {
        boundry(nums);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(nums[i][j]=='O') nums[i][j]='X';
                if(nums[i][j]=='T') nums[i][j]='O';
            }
        }
    }
};