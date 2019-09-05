class Solution:

    def generateMatrix(self,n):
        if n<1:
            return []
        if n == 1:
            return [[1]]


        matrix = [[-1 for i in range(n)] for j in range(n)]
        c = 0
        nn = n**2
        direction = 'r'
        i = 0
        j = 0
        while c<nn:
            if direction == 'r':
                while j<n and matrix[i][j] == -1:
                    c +=1 
                    matrix[i][j] = c
                    j += 1
                direction = 'd'
                j -= 1
                i += 1
            elif direction == 'd':
                while i<n and matrix[i][j] == -1:
                    c += 1
                    matrix[i][j] = c
                    i += 1
                direction = 'l'
                i -= 1
                j -= 1
            elif direction == 'l':
                while j>=0 and matrix[i][j] == -1:
                    c += 1
                    matrix[i][j] = c
                    j -= 1
                direction = 'u'
                j += 1
                i -= 1
            else:
                while i>= 0 and matrix[i][j] == -1:
                    c += 1
                    matrix[i][j] = c
                    i -= 1
                direction = 'r'
                i += 1
                j += 1

        return matrix
s = Solution()
print(s.generateMatrix(4))
