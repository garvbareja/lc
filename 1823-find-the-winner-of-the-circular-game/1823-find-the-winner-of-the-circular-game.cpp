class Solution {
public:
    int findTheWinner(int n, int k) {
        unordered_set<int> hash; int cur=0;
        while(hash.size()!=n-1){
            int temp=1;
            while(temp<k){
                cur=(cur+1)%n;
                if(!hash.count(cur)) temp++;
            }
            hash.insert(cur);
            while(hash.count(cur)) cur=(cur+1)%n;
        }
        return cur+1;
    }
};