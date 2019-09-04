class Solution:
#     def xx(self,s,i,dp):
#         if dp[i] != -1:
#             return dp[i]
        
#         if i == -1:
#             return 0
        
#         if i == 0:
#             dp[i] = 1
#         else:
#             if s[0:i+1] == s[0:i+1][::-1]:
#                 dp[i] = 2 + self.xx(s,i-1,dp)
#             else:
#                 dp[i] = 1 + self.xx(s,i-1,dp)
                
#         return dp[i]
    def xx(self,s,i,j,dp):
        
        if dp[i][j] != -1:
            return dp[i][j]
        
        if i == j:
            dp[i][j] = 1
        else:
            t = 0 if s[i:j+1] == s[i:j+1][::-1] else 0
            for k in range(i+1,j+1):
                t += self.xx(s,k,j,dp)
            dp[i][j] = t
        return dp[i][j]
    
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[-1]*n for i in range(n)]
        return self.xx(s,0,n-1,dp)
        
s = Solution()
print(s.countSubstrings("abc"))