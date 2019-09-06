class Solution:
    def xx(self, obstacleGrid, i, j, dp, n, m):
        if obstacleGrid[i][j] == 1:
            dp[i][j] == 0
            return 0
        if i == n-1 and j==m-1:
            dp[i][j] = 1
            return 1

        if dp[i][j] != -1:
            return dp[i][j]

        result = 0
        obstacleGrid[i][j] = -1
        # if i-1>=0 and obstacleGrid[i-1][j] != -1:
        #     result += self.xx(obstacleGrid, i-1, j, dp, n, m)
        if i+1< n and obstacleGrid[i+1][j] != -1:
            result += self.xx(obstacleGrid, i+1, j, dp, n, m)
        # if j-1 >=0 and obstacleGrid[i][j-1] != -1:
        #     result += self.xx(obstacleGrid, i, j-1, dp, n, m)
        if j+1 < m and obstacleGrid[i][j+1] != -1:
            result += self.xx(obstacleGrid, i, j+1, dp, n, m)
        obstacleGrid[i][j] = 0
        dp[i][j] = result
        return result


    def uniquePathsWithObstacles(self, obstacleGrid):
        if obstacleGrid == None or obstacleGrid == []:
            return 0

        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
        dp = [[-1 for i in range(m)] for j in range(n)]
        return self.xx(obstacleGrid, 0, 0, dp, n, m)

s = Solution()
# obstacleGrid= [[0,0,0],[0,1,0],[0,0,0]]
obstacleGrid = [
    [0,0,0,0],
    [0,1,0,0],
    [0,0,0,0],
    [0,0,1,0],
    [0,0,0,0]
]
print(s.uniquePathsWithObstacles(obstacleGrid))