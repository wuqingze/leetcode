/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution {
    public int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        while(i<=j){
            int mid = (j-i)/2+i;
            if(isBadVersion(mid)){
                if(isBadVersion(mid-1) == false){
                    return mid;
                }
                j = mid -1;
            }else{
                if(isBadVersion(mid+1)){
                    return mid+1;
                }
                i= mid+1;
            }
        }
        return -1;
    }

    public boolean isBadVersion(int n){
        return n >= 1702766719;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().firstBadVersion(2126753390));
    }
}

