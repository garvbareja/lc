class Solution {
public:
    vector<int> getRow(int rowindex) {
        if(rowindex==0) return {1};
        if(rowindex==1) return {1,1};
        vector<int> res={1,1};
        int curindex=2,prevval=1;
        while(curindex<=rowindex){
            prevval=1;
            for(int i=1;i<curindex;i++){
                int newprevval=res[i];
                res[i]+=prevval;
                prevval=newprevval;
            }
            curindex++;
            res.push_back(1);
        }
        return res;
    }
};