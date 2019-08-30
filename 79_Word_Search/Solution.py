class Solution:
    def ff(self, i, j, n, m, dp, l, word, board):
                
        if board[i][j] != word[l]:
            return False
        
        if l == len(word)-1:
            return True
        dp[i][j] = 1
        if i -1>-1 and dp[i-1][j] == -1:
            if self.ff(i-1,j,n,m,dp,l+1,word,board):
                return True
        
        if i +1<n and dp[i+1][j] == -1:
            if self.ff(i+1,j,n,m,dp,l+1,word,board):
                return True
            
        if j -1>-1 and dp[i][j-1] == -1:
            if self.ff(i,j-1,n,m,dp,l+1,word,board):
                return True
            
        if j+1<m and dp[i][j+1] == -1:
            if self.ff(i,j+1,n,m,dp,l+1,word,board):
                return True
        dp[i][j] = -1
        return False
    
    def exist(self, board, word):
        n = len(board)
        m = len(board[0])
        dp = [[-1 for i in range(m)] for j in range(n)]
        l = 0
        
        for i in range(n):
            for j in range(m):
                if self.ff(i,j,n,m,dp,l,word,board):
                    return True
                
        return False

# board = [["a","b"]]
board = [["a","a"]]
s = Solution()        
# s.exist(board,"ba")
s.exist(board,"aaa")