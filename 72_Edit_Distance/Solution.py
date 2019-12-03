class Solution:
    def f(self, word1, word2, i, j, n, m, dp):
        if i==n:
            if j == m:
                return 0
            if j < m:
                return m-j
            if j > m:
                return j - m
        if i < n:
            if j > m:
                return j - m
            if j == m:
                return n - i
        if dp[i][j] != -1:
            return dp[i][j]
        if word1[i] == word2[j]:
            count1 = 1 + self.f(word1, word2, i+1, j, n, m, dp)
            count2 = 1 + self.f(word1, word2, i, j+1, n, m, dp)
            count3 = self.f(word1, word2, i+1, j+1, n, m, dp)
            dp[i][j] = min(count1, count2, count3)
            return dp[i][j]
        else:
            count1 = 1 + self.f(word1, word2, i+1, j, n, m, dp)
            count2 = 1 + self.f(word1, word2, i, j+1, n, m, dp)
            count3 = 1 + self.f(word1, word2, i+1, j+1, n, m, dp)
            dp[i][j] = min(count1, count2, count3)
            return dp[i][j]
    
    def minDistance(self, word1, word2):
        if None == word1 or ''== word1:
            if None == word2 or ''==word2:
                return 0
            else:
                return len(word2)
        i = 0
        j = 0
        n = len(word1)
        m = len(word2)
        dp = [[-1 for j in range(m)] for i in range(n)]
        return self.f(word1, word2, i, j, n, m, dp)

s = Solution()
# print(s.minDistance("horse", "ros"))
print(s.minDistance("intention", "execution"))
        