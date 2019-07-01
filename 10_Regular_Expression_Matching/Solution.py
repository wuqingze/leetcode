class Solution:
    def match(self, p: str, s: str, i: int, j: int, n: int , m: int) ->bool:
        if i >=n:
            return j >= m
        if j >=m:
            return i >=n or (i+1<n and p[i+1]=='*' and self.match(p,s,i+2,j,n,m))
        if i == n-1:
            return (j == m-1) and (p[i]==s[j] or p[i]=='.')
        else:
            if p[i+1] == '*':
                if p[i] == s[j] or p[i] == '.':
                    return self.match(p,s,i,j+1,n,m) or self.match(p,s,i+2,j,n,m)
                else:
                    return self.match(p,s,i+2,j,n,m)
            else:
                if p[i] == s[j] or p[i]=='.':
                    return self.match(p,s,i+1,j+1,n,m)
                else:
                    return False

    def isMatch(self, s: str, p: str) -> bool:
        i = 0
        j = 0
        n = len(p)
        m = len(s)
        return self.match(p,s,i,j,n,m)
        
s = Solution()
# print(s.isMatch("aa","a"))
# print(s.isMatch("aa","a*"))
# print(s.isMatch("ab",".*"))
# print(s.isMatch("aab","c*a*b"))
# print(s.isMatch("mississippi","mis*is*p*."))
print(s.isMatch("aaa","a.a"))
