class Solution:
    def minPathSm(self,grid,i,j,n,m,dp):
        if i <0 or i >n-1 or j>m-1 or j<0:
            return 0
        if i == n-1 and j == m-1:
            return grid[i][j]
        elif dp[i][j] != 0:
            return dp[i][j]
        else:
            t = 0
            if i+1<n and j+1<m:
                t = grid[i][j]+min(self.minPathSm(grid,i+1,j,n,m,dp),self.minPathSm(grid,i,j+1,n,m,dp))
            elif j+1>=m:
                t =  grid[i][j]+self.minPathSm(grid,i+1,j,n,m,dp)
            else:
                t =  grid[i][j]+self.minPathSm(grid,i,j+1,n,m,dp)
            dp[i][j] =t
            return t           
                    
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid == None or grid == [] or grid==[[]]:
            return 0
        
        n = len(grid)
        m = len(grid[0])
        dp = [[0 for i in range(m)] for j in range(n)]
        return self.minPathSm(grid,0,0,n,m,dp)

grid = [[7,1,3,5,8,9,9,2,1,9,0,8,3,1,6,6,9,5],[9,5,9,4,0,4,8,8,9,5,7,3,6,6,6,9,1,6],[8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8],[6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4],[7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4],[9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9],[1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4],[3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2],[1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3],[5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7],[2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7],[0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9]]
s = Solution()
print(s.minPathSum(grid))