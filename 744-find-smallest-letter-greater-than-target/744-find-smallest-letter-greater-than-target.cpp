class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0,high=letters.size()-1,mid,res=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(letters[mid]<=target){
                low=mid+1;
            }else{
                high=mid-1;
                res=mid;
            }
        }
        cout<<res<<endl;
        return letters[res];
    }
};