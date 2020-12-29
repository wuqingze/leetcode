class Solution:
    def f(self, s, i, n, dp):
        if i >= n:
            return 0
        if i == n -1:
            if s[i] == '0':
                return 0
            else:
                return 1
        if i == n -2:
            if s[i] == '0':
                if s[i+1] == '0':
                    return 0
                else:
                    return 1
            elif s[i] == '1':
                if s[i+1]=='0':
                    return 1
                else:
                    return 2
            elif s[i] == '2':
                if s[i+1]=='0':
                    return 1
                elif s[i+1] in ['1','2','3','4','5','6']:
                    return 2
                else:
                    return 1

        if dp[i] != -1:
            return dp[i]

        if s[i] == '0':
            if i<n-1 and s[i+1] != 0:
                dp[i] = self.f(s,i+2,n,dp)
                return dp[i]
            else:
                dp[i] = 0
                return dp[i]
        elif s[i] == '1':
            dp[i] = self.f(s, i+1,n,dp)+self.f(s,i+2,n, dp)
            return dp[i]
        elif s[i] =='2':
            if i< n-1 and s[i+1] in ['0','1','2','3','5','6']:
                dp[i] = self.f(s, i+1,n,dp)+self.f(s,i+2,n, dp)
                return dp[i]
            else:
                dp[i] = self.f(s, i+2,n,dp)
                return dp[i]
        else:
            dp[i] = self.f(s, i+1, n, dp)
            return dp[i]

    def numDecodings(self, s):
        if None == s or ''==s:
            return 0
        n = len(s)
        dp = [-1 ]*n
        return self.f(s,0,n,dp)

s = Solution()
print(s.numDecodings("27"))
print(s.numDecodings("12"))
print(s.numDecodings("226"))
        