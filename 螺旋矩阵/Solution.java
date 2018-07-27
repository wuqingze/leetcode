class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        
        char move = 'r';
        int count = 1;
        int x = 0;
        int y = 0;
        while(count<=n*n){
            switch(move){
                case 'u':
                    while(y>=0 && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        y -= 1;
                    }
                    move = 'r';
                    x += 1;
                    break;
                case 'd':
                    while(y<n && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        y += 1;
                    }
                    move = 'l';
                    x -= 1;
                    break;
                case 'l':
                    while(x>=0 && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        x -= 1;
                    }
                    move = 'u';
                    y -= 1;
                    break;
                case 'r':
                    while(x<n && result[y][x] == 0){
                        result[y][x] = count;
                        count += 1;
                        x += 1;
                    }
                    move = 'd';
                    y += 1;
                    break;
            }            
        }
        return result;
    }
}