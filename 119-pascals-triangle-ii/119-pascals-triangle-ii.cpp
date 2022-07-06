class Solution {
public:
    vector<int> getRow(int rowindex) {
        if(rowindex==0) return {1};
        if(rowindex==1) return {1,1};
        vector<int> cur={1,1}; int curindex=2,prevval=1;
        while(curindex<=rowindex){
            prevval=1;
            for(int i=1;i<curindex;i++){
                int newval=cur[i];
                cur[i]+=prevval;
                prevval=newval;
            }
            cur.push_back(1);
            curindex++;
        }
        return cur;
    }
};