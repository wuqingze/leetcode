class Solution:
    def spiralOrder(self, matrix):
        if matrix == None or len(matrix)==0:
            return []
        m = len(matrix)
        n = len(matrix[0])
        
        mark = [[ -1 for i in range(n)] for ii in range(m)]
        
        i = 0
        j = 0
        d = 'r'
        
        result = []
        count = 0
        total = n * m
        while count < total:
            if d == 'r':
                while i < m and j < n and i > -1 and j>-1 and mark[i][j] == -1:
                    mark[i][j] = 0
                    result.append(matrix[i][j])
                    count += 1
                    j += 1
                d = 'd'
                j -= 1
                i += 1
            elif d == 'd':
                while i < m and j < n and i > -1 and j>-1 and mark[i][j] == -1:
                    mark[i][j] = 0
                    result.append(matrix[i][j])
                    count += 1
                    i += 1
                d = 'l'
                i -= 1
                j -= 1
            elif d == 'l':
                while i < m and j < n and i > -1 and j>-1 and mark[i][j] == -1:
                    mark[i][j] = 0
                    result.append(matrix[i][j])
                    count += 1
                    j -= 1
                d = 'u'
                j += 1
                i -= 1
            else:
                while i < m and j < n and i > -1 and j>-1 and mark[i][j] == -1:
                    mark[i][j] = 0
                    result.append(matrix[i][j])
                    count += 1
                    i -= 1
                d = 'r'
                i += 1
                j += 1 
        return result

s = Solution()
matrix = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
# matrix = [
#     [1,2],
#     [4,5]
# ]
print(s.spiralOrder(matrix))