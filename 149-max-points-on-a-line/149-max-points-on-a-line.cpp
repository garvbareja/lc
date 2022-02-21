class Solution {
public:
    pair<double,double> help(double x1,double y1,double x2,double y2){
        if(x2-x1==0) return {INT_MAX,x1};
        double m = (y2-y1)/(x2-x1);
        double c = y1 - (m*x1);
        return {m,c};
    }
    
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        map<pair<double,double>,set<pair<int,int>>> hash; int ans=0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                pair<double,double> slopeny = help(points[i][0],points[i][1],points[j][0],points[j][1]);
                if(hash.count(slopeny)){
                    hash[slopeny].insert({points[j][0],points[j][1]});
                }else{
                    hash[slopeny].insert({points[i][0],points[i][1]});
                    hash[slopeny].insert({points[j][0],points[j][1]});
                }
                if(ans<hash[slopeny].size()) ans=hash[slopeny].size();
            }
        }
        return ans;
    }
};