class Solution:
    def __init__(self):
        self.axis = [(-1,0),(1,0),(0,-1),(0,1)]

    def dfs(self,matrix,i,j,n,m,dp):
        if i<0 or i>n-1 or j<0 or j>m-1:
            return 0
        if dp[i][j] != 1:
            return dp[i][j]
        else:
            mx = 0
            for ax in self.axis:
                x = ax[0]+i
                y = ax[1]+j
                if (x<0 or x>n-1 or y<0 or y>m-1):
                    continue
                else:
                    if matrix[i][j]>matrix[x][y]:
                        mx = max(mx,self.dfs(matrix,x,y,n,m,dp))
            dp[i][j] = mx + 1
            return dp[i][j]
        
         
    
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if matrix == None or matrix == [] or matrix == [[]]:
            return 0
        
        n = len(matrix)
        m = len(matrix[0])
        ans = 0
        dp = [[1 for i in range(m)] for j in range(n)]
        for i in range(n):
            for j in range(m):
                ans = max(ans,self.dfs(matrix,i,j,n,m,dp))
                
        return ans
                
s = Solution()
# print(s.longestIncreasingPath([[9,9,4],[6,6,8],[2,1,1]]))
print(s.longestIncreasingPath([[0],[1],[5],[5]]))