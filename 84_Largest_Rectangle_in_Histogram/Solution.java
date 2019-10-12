import java.util.*;

public class Solution {
    public int largestRectangleArea(int[] height) {
        int len = height.length;
        Stack<Integer> s = new Stack<Integer>();
        int maxArea = 0;
        for(int i = 0; i < len; i++){
            // int h = (i == len ? 0 : height[i]);
            int h = height[i];
            if(s.isEmpty() || h >= height[s.peek()]){
                s.push(i);
            }else{
                int tp = s.pop();
                maxArea = Math.max(maxArea, height[tp] * (s.isEmpty() ? i : i - 1 - s.peek()));
                i--;
            }
        }
        return maxArea;
    }

    public static void main(String[] args){
        Solution s = new Solution();
        // System.out.println(s.largestRectangleArea(new int[]{2,1,5,6,2,3}));
        System.out.println(s.largestRectangleArea(new int[]{2,1,2}));
    }
}