class Solution(object):
    def surroundingcount(self,board,i,j,m,n):
        ans = 0
        for k in range(i-1,i+2):
            for l in range(j-1,j+2):
                if k >=0 and k<n and l>=0 and l<m:
                    ans += board[k][l]
                    
        return ans if board[i][j]==0 else ans-1
                    
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        n = len(board)
        m = len(board[0])
        
        temp = [[0 for i in range(m)] for j in range(n)]
        
        # old = [ list(l) for l in board]
        
        for i in range(n):
            for j in range(m):
                sc = self.surroundingcount(board,i,j,m,n)
                if board[i][j]==1:
                    if sc <2:
                        temp[i][j]=0
                    elif sc==2 or sc==3:
                        temp[i][j] =1
                    elif sc > 3:
                        temp[i][j] = 0
                else:
                    if sc == 3:
                        temp[i][j] = 1
                        
        for i in range(n):
            for j in range(m):
                board[i][j]= temp[i][j]

s = Solution()
board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
s.gameOfLife(board)
print(board)