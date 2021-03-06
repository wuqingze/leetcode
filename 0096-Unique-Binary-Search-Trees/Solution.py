class Solution:

    def numTrees(self, n):
        dp = [1]

        for i in range(1, n+1):
            dp.append(0)
            for j in range(i):
                dp[i] += dp[j]*dp[i-j-1]
        return dp[-1]


s = Solution()
print(s.numTrees(1))
print(s.numTrees(2))
print(s.numTrees(3))
print(s.numTrees(4))
