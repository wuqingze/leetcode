import java.util.*;
class Solution {
    public int[] countBits(int num) {
        int[] r = new int[num+1];
        for(int i=0; i<=num; i++){
            int count = 0;
            int n = i;
            while(n!=0){
                if(n%2 == 1){
                    count += 1;
                }
                n = n/2;
            }
            r[i]=count;
        }
        return r;
    }

     public static int findComplement(int num) {
        int bitcount = 0;
        int n = num;
        while(n != 0){
            bitcount += 1;
            n /= 2;
        }
        return num ^ (0xffffffff>>>(32-bitcount));
    }
    

    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        
        char move = 'r';
        int count = 1;
        int x = 0;
        int y = 0;
        while(count<=n){
            switch(move){
                case 'u':
                    while(y>=0 && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        move = 'l';
                        y -= 1;
                    }
                    continue;
                case 'd':
                    while(y<n && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        move = 'l';
                        y += 1;
                    }
                    continue;
                case 'l':
                    while(x>=0 && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        move = 'u';
                        x -= 1;
                    }
                    continue;
                case 'r':
                    while(x<n && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        move = 'd';
                        x += 1;
                    }
                    continue;
            }            
        }
        return result;
    }
    
    public static void main(String[] args) {
        // int[] r = new Solution().countBits(2);
        // System.out.println(Arrays.toString(r));

        // System.out.println(findComplement(5));
        int[][] r = new int[3][3];
        for(int i=0;i<r.length; i++){
            for(int j=0; j<r.length; j++){
                System.out.print(r[i][j]);
            }
            System.out.println("");
        }
    }
} 