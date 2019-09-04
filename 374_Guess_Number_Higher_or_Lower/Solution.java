/* The guess API is defined in the parent class GuessGame.
@param num, your guess
@return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num); */

public class Solution {
    public int guessNumber(int n) {
        int i = 1;
        while(i <= n){
            int mid = (n+i)/2;
            int t = guess(mid);
            if (t == 0) return mid;
            if(t == -1){
                i = mid +1;
            }else{
                n = mid -1;
            }
        }
        return 0;
    }
    public static int guess(int n){
        if(n == 6) return 0;
        if(n< 6) return -1;
        if(n> 6) return 1;

        return 0;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.guessNumber(10));
    }
}