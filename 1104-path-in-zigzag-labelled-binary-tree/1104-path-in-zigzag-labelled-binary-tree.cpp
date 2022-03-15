class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

        vector<int>result;
        
        int depth = log10(label)/log10(2);
        while(depth>=0)
        {
            result.push_back(label);
            label = (int)pow(2,depth-1) + (int)pow(2,depth) - 1 - label/2;
            depth--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};