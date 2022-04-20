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
    int guessNumber(int n,int low=1,int mid=0) {
        while(low<=n){
            mid=low+(n-low)/2;
            if(!guess(mid)) return mid;
            if(guess(mid)==-1) n=mid-1;
            else low=mid+1;
        }
        return 0;
    }
};