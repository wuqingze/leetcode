class Solution:
    def rownull(self, board, i):
        result = [str(i) for i in range(1,10)]
        for j in range(9):
            if board[i][j] != '.' and board[i][j] in result:
                result.remove(board[i][j])
        
        return result
    def colnull(self, board, j):
        result = [str(j) for j in range(1,10)]
        for i in range(9):
                if board[i][j] != '.' and board[i][j] in result:
                    result.remove(board[i][j])
        return result

    def leftupToRightdown(self, board):
        result = [str(i) for i in range(1,10)]
        for i in range(9):
            if board[i][i] != '.' and board[i][i] in result:
                result.remove(board[i][i])
        
        return result

    def leftdownToRightup(self, board):
        result = [str(i) for i in range(1,10)]
        for i in range(9):
            if board[i][8-i] != '.' and board[i][8-i] in result:
                result.remove(board[i][8-i])
        
        return result

    def gridnull(self, board, i, j):
        result = [str(i) for i in range(1,10)]
        ii = (i//3)*3
        jj = (j//3)*3
        for k in range(ii,ii+3):
            for l in range(jj,jj+3):
                if board[k][l] != '.' and board[k][l] in result:
                    result.remove(board[k][l])
        return result
    
    def isOk(self,board, i, j):
        result = True
        t = []
        for jj in range(9):
            if board[i][jj] == '.':
                    continue
            if board[i][jj] in t:
                return False
            t.append(board[i][jj])
        
        t = []
        for ii in range(9):
            if board[ii][j] == '.':
                continue
            if board[ii][j] in t:
                return False                
            t.append(board[ii][j])
        
        # t = []
        # if i == j:
        #     for ii in range(9):
        #         if board[ii][ii] == '.':
        #             continue
        #         if board[ii][ii] in t:
        #             return False
        #         t.append(board[ii][ii])
        # t = []
        # if i == 8-j:
        #     for ii in range(9):
        #         if board[ii][8-ii] == '.':
        #             continue
        #         if board[ii][8-ii] in t:
        #             return False
        #         t.append(board[ii][8-ii])

        ii == i//3 
        jj == j//3
        t = []
        for k in range(ii,ii+3):
            for l in range(jj,jj+3):
                if board[k][l] == '.':
                    continue
                if board[k][l] in t:
                    return False
                t.append(board[k][l])
        
        return result
    
    def backtrack(self, board, i, j):
        if i==j and i==8 and board[i][j] != '.':
            return True
        
        rownull = self.rownull(board,i)
        colnull = self.colnull(board,j)
        gridnull = self.gridnull(board,i,j)
        leftupToRightdownNull = []
        # if i == j:
        #     leftupToRightdownNull = self.leftupToRightdown(board)
        # leftdownToRightupNull = []
        # if i == 8-j:
        #     leftdownToRightupNull = self.leftdownToRightup(board)

        if i==j and i==8 and board[i][j] == '.':
            if len(rownull) == 1 and len(colnull) == 1 and len(gridnull) == 1 and rownull[0] == colnull[0] == gridnull[0]:
                board[i][j] = rownull[0]
                return True
            else:
                return False

        if board[i][j] != '.':
            if j == 8:
                return self.backtrack(board, i+1,0)
            else:
                return self.backtrack(board, i, j+1)
        else:
            t = []
            for n in [str(ii) for ii in range(1,10)]:
                if n in rownull and n in colnull and n in gridnull:
                        t.append(n)
                # if i == 8-j:
                #     if n in rownull and n in colnull and n in gridnull and n in leftdownToRightupNull:
                #         t.append(n)
                # elif i == j:
                #     if n in rownull and n in colnull and n in gridnull and n in leftupToRightdownNull:
                #         t.append(n)
                # else:
                #     if n in rownull and n in colnull and n in gridnull:
                #         t.append(n)
            if [] == t:
                return False
            else:
                for n in t:
                    board[i][j] = n
                    tr = False
                    
                    if j == 8:
                        tr = self.backtrack(board,i+1,0)
                    else:
                        tr = self.backtrack(board,i,j+1)
                    
                    if tr:
                        return True
                    else:
                        board[i][j] = '.'
                return False
    
    def solveSudoku(self, board):
            """
            Do not return anything, modify board in-place instead.
            """
            self.backtrack(board,0,0)
            return board

if __name__ == "__main__":
    board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    # board = [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","."]]
    s = Solution()
    print(s.solveSudoku(board))
