import java.util.*;
class Solution {
    public static int myn = 1000000;
    public static int[] dp = new int[myn+1];
    static{
        dp[0] = 0;
        for(int i=1;i<myn;i++){
            dp[i] = 0x7ffffffe;
        }
        for(int i=1;i<=myn;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = Math.min(dp[i],dp[i-j*j]+1);
            }    
        }
    }
    public int numSquares(int n) {
        if(myn >= n){
            return dp[n];
        }
        else{
            int[] ndp = new int[n+1];
            for(int i=0;i<myn;i++){
                ndp[i] = dp[i];
            }
            for(int i=myn;i<n;i++){
                ndp[i] = 0x7fffffff;
            }
            for(int i=myn+1;i<=n;i++){
                for(int j=1;j*j<=i;j++){
                    dp[i] = Math.min(dp[i],dp[i-j*j]+1);
                }  
            }
            return ndp[n];
        }
    }

    public static void main(String[] args) {
        System.out.println(new Date().getTime());
        Solution s = new Solution();
        System.out.println(s.numSquares(3));
        System.out.println(new Date().getTime());
    }
}