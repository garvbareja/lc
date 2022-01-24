class Solution {
public:
    int color;
    bool valid(vector<vector<int>>& image,int i,int j){
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=color) return false;
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        color=image[sr][sc];
        queue<pair<int,int>> q; q.push({sr,sc});
        image[sr][sc]=newColor;
        if(color==newColor) return image;
        vector<int> x = {-1,+1,0,0};
        vector<int> y = {0,0,-1,+1};
        while(!q.empty()){
            pair<int,int> front = q.front(); q.pop();
            for(int i=0;i<4;i++){
                if(valid(image,front.first+x[i],front.second+y[i])){
                    image[front.first+x[i]][front.second+y[i]] = newColor;
                    q.push({front.first+x[i],front.second+y[i]});
                }
            }
        }
        return image;
    }
};