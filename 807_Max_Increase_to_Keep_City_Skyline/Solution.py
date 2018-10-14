class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])
        rmx = []
        cmx = []
        
        for i in range(n):
            mx = grid[i][0]
            for j in range(m):
                mx = max(mx,grid[i][j])
            rmx.append(mx)
            
        for i in range(m):
            mx = grid[0][i]
            for j in range(n):
                mx = max(mx,grid[j][i])                
            cmx.append(mx)
        ans = 0
        for i in range(n):
            for j in range(m):
                t = grid[i][j]
                grid[i][j] = min(rmx[i],cmx[j])
                ans += grid[i][j]-t
                
        return ans

s = Solution()
# print(s.maxIncreaseKeepingSkyline([[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]))
print(s.maxIncreaseKeepingSkyline([[59,88,44],[3,18,38],[21,26,51]]))