class Solution:
    def surroundingcount(self,board,row,col,n,m):
        cnt = 0
        for i in range(row-1,row+2):
            if i >= n or i<0:
                continue
            for j in range(col-1,col+2):
                if j>=m or j<0:
                    continue
                if board[i][j] == 'M':
                    cnt += 1
                    
        return cnt

    def dfs(self,board,row,col,n,m):
        cnt = self.surroundingcount(board,row,col,n,m)
        if cnt == 0:
            board[row][col] = 'B'
            for i in range(row-1,row+2):
                if i>=n or i<0:
                    continue
                for j in range(col-1,col+2):
                    if j>=m or j<0:
                        continue
                    if board[i][j] == 'E':
                        self.dfs(board,i,j,n,m)   
        else:
            board[row][col] = str(cnt)
            
                     
                    
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        if board[click[0]][click[1]] == 'M':
            board[click[0]][click[1]] = 'X'
            return board
        elif board[click[0]][click[1]] == 'E':
            n = len(board)
            m = len(board[0])
            self.dfs(board,click[0],click[1],n,m)
        return board
                    
        
s = Solution()
board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]
click = [3,0]
print(s.updateBoard(board,click))


