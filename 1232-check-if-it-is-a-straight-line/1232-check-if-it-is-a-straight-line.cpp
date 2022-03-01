class Solution {
public:
    double slp(int &x1,int &y1,int &x2,int &y2){
        if(x1==x2) return INT_MAX;
        return (y2-y1)/(double)(x2-x1);
    }
    
    bool checkStraightLine(vector<vector<int>>& cor){
        double slope=slp(cor[0][0],cor[0][1],cor[1][0],cor[1][1]);
        for(int i=2;i<cor.size();i++) if(slope!=slp(cor[i-1][0],cor[i-1][1],cor[i][0],cor[i][1])) return false;
        return true;
    }
};