class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        dp = [[False]*n for i in range(n)]
        ans = ""
        for i in range(n-1,-1,-1):
            for j in range(i,n):
                dp[i][j] = (s[i] == s[j]) and  ( (j-i) < 3 or dp[i+1][j-1])
                if(dp[i][j]  and ((ans == "") or (j-i+1)>len(ans))):
                    ans = s[i:j+1]
        return ans

s = Solution()
ans = s.longestPalindrome("babad")

print(ans)