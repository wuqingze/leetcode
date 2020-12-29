/**
 * Solution
 */
public class Solution {
    public int countBattleships(char[][] board) {
        int m = board.length;
        if (m==0) return 0;
        int n = board[0].length;
        
        int count=0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '.') continue;
                if (i > 0 && board[i-1][j] == 'x') continue;
                if (j > 0 && board[i][j-1] == 'x') continue;
                count++;
            }
        }
        
        return count;
    }

    public static void main(String[] args) {
        char[][] g = {{'.','.','.','x'},{'x','x','x','x'},{'.','.','.','x'}};
        Solution s = new  Solution();
        System.out.println(s.countBattleships(g));
    }
}