class Solution(object):
    def binsrch(self,nums,val):
        n = len(nums)
        l = 0
        r = n-1
        while l<=r:
            mid = l+(r-l)//2
            if nums[mid] ==val:
                return True
            if nums[mid]>val:
                r = mid -1
            else:
                l = mid +1
        return False
    
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if matrix == None or matrix == [] or matrix == [[]]:
            return False
        n = len(matrix)
        m = len(matrix[0])
        for i in range(min(m,n)):
            if matrix[i][i] == target:
                return True
            
            elif matrix[i][i]>target:
                for j in range(i,-1,-1):
                    if matrix[i][j] == target:
                        return True
                for j in range(i,-1,-1):
                    if matrix[j][i] == target:
                        return True
        if n>m:
            for i in range(m,n):
                if matrix[i][m-1] == target:
                    return True
        elif n<m:
            for i in range(n,m):
                if matrix[n-1][i] == target:
                    return True
        return False

        # for i in range(len(matrix)):
        #     if matrix[i][0]> target or matrix[i][-1]<target:
        #         continue
            
        #     if self.binsrch(matrix[i],target):
        #         return True
            
        # return False

# matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
# val = 5

matrix = [[2,5],[2,8],[7,9],[7,11],[9,11]]
val = 7
s = Solution()
print(s.searchMatrix(matrix,val))