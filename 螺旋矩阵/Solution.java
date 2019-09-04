import java.util.Arrays;

class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        
        int x = 0;
        int y = 0;
        int count = 1;
        int total  = n*n;
        char move = 'r';
        while(count<=total){
            switch(move){
                case 'u':
                    while(y>=0 && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        y -= 1;
                    }
                    y += 1;
                    x += 1;
                    move = 'r';
                    break;
                case 'd':
                    while(y<n && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        y += 1;    
                    }
                    y -= 1;
                    x -= 1;
                    move = 'l';
                    break;
                case 'l':
                    while(x>=0 && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        x -= 1;
                    }
                    x += 1;
                    y -= 1;
                    move = 'u';
                    break;
                case 'r':
                    while(x<n && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        x += 1;
                    }
                    x -= 1;
                    y += 1;
                    move = 'd';
                    break;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Solution().generateMatrix(3)));
    }
}