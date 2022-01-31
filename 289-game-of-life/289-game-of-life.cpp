class Solution {
public:
    bool valid(vector<vector<int>>& nums,int i,int j){
        if(i<0 || i>=nums.size() || j<0 || j>=nums[i].size()) return false;
        return true;
    }
    
    int help(vector<vector<int>>& nums,int i,int j){
        int n=0;
        vector<int> x={0,1,0,-1,-1,1,1,-1};
        vector<int> y={1,0,-1,0,1,1,-1,-1};
        for(int z=0;z<8;z++) if(valid(nums,i+x[z],j+y[z]) && nums[i+x[z]][j+y[z]]>0) n++;
        return n;
    }
    
    void gameOfLife(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                int n=help(nums,i,j);
                if(nums[i][j]){
                    if(!(n==2||n==3)) nums[i][j]=2;
                }else{
                    if(n==3) nums[i][j]=-1;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(nums[i][j]==2) nums[i][j]=0;
                else if(nums[i][j]==-1) nums[i][j]=1;
            }
        }
    }
};