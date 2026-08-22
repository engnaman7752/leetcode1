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
        int low=1;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int response=guess(mid);
            //cout<<mid<<response<<endl;
            if(response==-1){
                high=mid-1;
            }
            else if(response==1){
                low=mid+1;
            }
            else
            return mid;
        }
        return low;
    }
};