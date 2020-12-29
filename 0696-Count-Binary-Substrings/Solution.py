class Solution:
    def xx(self,s):
        t = 0
        for i in range(len(s)):
            if s[i] == '0':
                t +=1
            else:
                t -= 1
        return t == 0
    
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        t = {}
        ans = 0
        for i in range(2,n+1,2):
            j = 0
            while j <= n -i:
                if t.get(s[j:j+i]) == None:
                    dd = self.xx(s[j:j+i])
                    if dd:
                        t[s[j:j+i]] = True
                        ans += 1
                    else:
                        t[s[j:j+i]] = False
                        
                j += 1
        return ans

s = Solution()
print(s.countBinarySubstrings("00110"))