class Solution:
    def leftup(self, board, i,j,n):
        result = True
        ii = i - 1
        jj = j - 1
        while ii>=0 and jj>=0:
            if board[ii][jj] == 1:
                result = False
                break
            ii -= 1
            jj -= 1
        return result

    def rightup(self, board, i,j,n):
        result = True
        ii = i-1
        jj = j +1
        while ii>=0 and jj <n:
            if board[ii][jj] == 1:
                result = False
                break
            ii -= 1
            jj += 1
        return result
    def listToStr(self, l):
        s = ''
        for c in l:
            if c == 0:
                s += '.'
            else:
                s += 'Q'
        return s
    def backtracking(self, board, i, j, n, result, col):
        if not self.leftup(board, i, j, n) or not self.rightup(board, i, j, n) or col[j]:
            return 
        
        board[i][j] = 1
        col[j] = True

        if i == n-1:
            result.append([self.listToStr(line) for line in board])
            board[i][j] = 0
            col[j] = False
            return

        for jj in range(n):
            self.backtracking(board, i+1, jj, n, result, col)
        board[i][j] = 0
        col[j] = False
    def solveNQueens(self,n):
        if n <=0 :
            return []

        if n == 1:
            return [['Q']]

        if n == 2:
            return []
        result = []
        col = [False for i in range(n)]
        board = [ [ 0 for i in range(n)] for j in range(n)]
        for i in range(n):
            board[0][i] = 1
            col[i] = True
            for j in range(n):
                self.backtracking(board, 1,j,n,result,col)
            board[0][i] = 0
            col[i] = False
        return result
s = Solution()
print(s.solveNQueens(9))

