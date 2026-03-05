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
        int low = 0, high = INT_MAX;

        while(low<=high){
            int mid = low+(high-low)/2;

            int fn = guess(mid);
            if(fn == -1) high = mid-1;
            else if(fn == 1) low = mid+1;
            else return mid;
        }
        return 0;
    }
};