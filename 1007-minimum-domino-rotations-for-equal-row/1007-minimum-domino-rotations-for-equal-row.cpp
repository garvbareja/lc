class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int cur=tops[0],i=0,count=0,ans=INT_MAX;
        while(i<tops.size() && (tops[i]==cur || bottoms[i]==cur)){
            if(tops[i]!=cur) count++;
            i++;
        }
        if(i>=tops.size()) ans=min(ans,count);
        cur=bottoms[0]; i=0; count=0;
        while(i<tops.size() && (tops[i]==cur || bottoms[i]==cur)){
            if(bottoms[i]!=cur) count++;
            i++;
        }
        if(i>=tops.size()) ans=min(ans,count);
        cur=bottoms[0]; i=0; count=0;
        while(i<tops.size() && (tops[i]==cur || bottoms[i]==cur)){
            if(tops[i]!=cur) count++;
            i++;
        }
        if(i>=tops.size()) ans=min(ans,count);
        cur=tops[0]; i=0; count=0;
        while(i<tops.size() && (tops[i]==cur || bottoms[i]==cur)){
            if(bottoms[i]!=cur) count++;
            i++;
        }
        if(i>=tops.size()) ans=min(ans,count);
        return ans==INT_MAX?-1:ans;
    }
};