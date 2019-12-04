class Solution:
    def colBinarySearch(self, matrix, i, j, m, target):
        low = j
        hight = m -1 
        while low <= hight:
            mid = (low+hight)//2
            if matrix[i][mid] == target:
                return True
            if matrix[i][mid] < target:
                low = mid + 1
            if matrix[i][mid] > target:
                hight = mid -1
        return False
    
    def rowBinarySearch(self, matrix, i, j, n, target):
        low = i
        hight = n -1
        while low<=hight:
            mid = (low+hight)//2
            if matrix[mid][j] == target:
                return True
            if matrix[mid][j] < target:
                low = mid + 1
            if matrix[mid][j] > target:
                hight = mid - 1
        return False
    
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if None == matrix or [] == matrix or [[]] == matrix:
            return False
        
        n = len(matrix)
        m = len(matrix[0])
        for i in range(n):
            for j in range(i, m):
                if self.colBinarySearch(matrix, i, j, m, target):
                    return True
                if self.rowBinarySearch(matrix, i, j, n, target):
                    return True
        return False