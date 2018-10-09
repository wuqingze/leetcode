class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        n = len(matrix)
        m = len(matrix[0])
        
        i = 0
        j = 0 
        flag = True
        
        rs = 0
        while i < n and j < m:
            mark = matrix[i][j]
            while i < n and j < m:
                if mark != matrix[i][j]:
                    return False
                else:
                    i += 1
                    j += 1
            rs += 1
            i = 0 
            j = rs
        
        i = n -1
        j = 0
        ic = n -1
        while i>0 and j < (m//2):
            mark = matrix[i][j]
            while i<n and j<(m//2):
                if mark != matrix[i][j]:
                    return False
                else:
                    i += 1
                    j += 1
            ic -= 1
            i = ic
            j = 0
        return True

s = Solution()
m = [[41,45],[81,41],[73,81],[47,73],[0,47],[79,76]]
print(s.isToeplitzMatrix(m))