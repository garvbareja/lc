/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1,high=n,mid,flag;
        while(low<=high){
            mid=low+(high-low)/2;
            flag=guess(mid);
            if(!flag) return mid;
            if(flag==1) low=mid+1;
            else high=mid-1;
        }
        return 1;
    }
};