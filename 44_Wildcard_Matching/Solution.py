class Solution:
    def match(self,s,p,i,j,n,m,dp):
        if j>=m:
            return i<n
        if i>=n:
            return (p[j]=='*' and self.match(s,p,i,j+1,n,m,dp))
        
        if dp.get(str(i)+','+str(j),None) != None:
            return dp.get(str(i)+','+str(j))
        else:
            if p[j] == '?' or p[j] == s[i]:
                dp[str(i)+','+str(j)] = True
                return self.match(s,p,i+1,j+1,n,m,dp)
            elif p[j] == '*':
                dp[str(i)+','+str(j)] = self.match(s,p,i,j+1,n,m,dp) or self.match(s,p,i+1,j+1,n,m,dp) or self.match(
                s,p,i+1,j,n,m,dp)
                return dp[str(i)+','+str(j)]
            else:
                dp[str(i)+','+str(j)] = False
                return False
        
    def match_(self, s, p, i, j, dp):
        if i == -1 and j == -1:
            return True
        if j == -1:
            return False
        if i == -1:
            return  p[j]=='*' and self.match_(s,p,i,j-1,dp)
        
        key = str(i)+","+str(j)
        
        if dp.get(key,None) != None:
            return dp.get(key)

        if s[i] == p[j] or p[j] == '?':
            dp[key] = self.match_(s,p,i-1,j-1,dp)            
        elif p[j] == '*':
            dp[key] = self.match_(s,p,i-1,j-1,dp) or self.match_(s,p,i-1,j,dp) or self.match_(s,p,i,j-1,dp)
        else:
            dp[key] = False
        return dp[key]

    def isMatch(self, s: str, p: str) -> bool:
        
        i = 0
        j = 0
        n = len(s)
        m = len(p)
        dp = {}
        return self.match(s,p,i,j,n,m,dp)


s = Solution()
s.isMatch("acdcb","a*c?b")