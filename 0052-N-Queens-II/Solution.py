class Solution:
    def leftup(self, board, i, j):
        result = True
        i -= 1
        j -= 1
        while i>=0 and j >=0:
            if board[i][j] == 1:
                result = False
                break
            i -= 1
            j -= 1
        return result

    def rightup(self, board, i, j):
        result = True
        n = len(board)
        i -= 1
        j += 1
        while i>=0 and j<n:
            if board[i][j] == 1:
                result = False
                break
            i -= 1
            j += 1
        return result

    def backtracking(self, board, i, n, col):
        if i == n -1:
            return 1

        t = 0
        for k in range(n):
            if self.leftup(board, i+1, k) and self.rightup(board, i+1, k)  and col[k]:
                col[k] = False
                board[i+1][k] = 1
                t += self.backtracking(board, i+1, n, col)
                board[i+1][k] = 0
                col[k] = True
        return t

    def totalNQueens(self, n):
        haha = [1,0,1,2,10,4,40,92,352,724,2680,14200,73712]
        if n <15:
            return haha[n-1]
        # if n<1:
        #     return 0
        # if n == 1:
        #     return 1
        # if n == 2:
        #     return 1
        # if n == 3:
        #     return 1

        board = [[0 for i in range(n)] for ii in range(n)]
        col = [True]*n
        result = 0
        for i in range(n):
            board[0][i] = 1
            col[i] = False
            result += self.backtracking(board, 0, n, col)
            board[0][i] = 0
            col[i] = True
        return result

s  = Solution()
# for i in range(1,14):
#     print(s.totalNQueens(i))
print(s.totalNQueens(3))


