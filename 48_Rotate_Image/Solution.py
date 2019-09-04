class Solution(object):
    def swap(self, matrix , i , j):
        temp = matrix[i][j]
        matrix[i][j]=matrix[j][i]
        matrix[j][i] = temp
    
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        for i in range(n):
            for j in range(i,n):
                self.swap(matrix,i,j)

        for i in range(n):
            for j in range(0,n//2):
                temp = matrix[i][j]
                matrix[i][j] = matrix[i][n-j-1]
                matrix[i][n-j-1] - temp
                
s = Solution()
print(s.rotate([[1,2,3],[4,5,6],[7,8,9]]))