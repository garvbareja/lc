/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* buildtree(vector<vector<int>>& grid,int top,int bottom,int left,int right){
        if(top>bottom || left>right) return nullptr;
        int val=grid[top][left];
        for(int i=top;i<=bottom;i++){
            for(int j=left;j<=right;j++){
                if(grid[i][j]!=val){
                    return new Node(0,false,buildtree(grid,top,(top+bottom)/2,left,(left+right)/2),buildtree(grid,top,(top+bottom)/2,((left+right)/2)+1,right),buildtree(grid,((top+bottom)/2)+1,bottom,left,(left+right)/2),buildtree(grid,((top+bottom)/2)+1,bottom,((left+right)/2)+1,right));
                }
            }
        }
        return new Node(val,true);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return buildtree(grid,0,grid.size()-1,0,grid[0].size()-1);
    }
};