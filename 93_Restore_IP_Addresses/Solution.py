class Solution:
    def f(self, c, i, n, tl, result, s):
        if i>n-1 or c>4:
            return
        
        if c == 4:
            if (n-i==1) or (n-i==2 and 9<int(s[i:n])<100) or (n-i==3 and 99<int(s[i:n])<256):
                tl.append(s[i:n])
                result.append(tl[0]+'.'+tl[1]+'.'+tl[2]+'.'+tl[3])
                tl.pop()
            return
    
        tl.append(s[i])
        self.f(c +1, i+1,n, tl, result, s)
        tl.pop()
        
        if i<n-2 and s[i] != '0':
            tl.append(s[i:i+2])
            self.f(c+1, i+2, n, tl, result, s)
            tl.pop()
        if i<n-3 and 99<int(s[i:i+3])<256:
            tl.append(s[i:i+3])
            self.f(c+1, i+3, n, tl, result, s)
            tl.pop()
    def restoreIpAddresses(self, s):
        if None == s or ''==s:
            return []
        n = len(s)
        if n>12 or n<4:
            return []
        
        result = []
        self.f(1, 0, n, [], result, s)
        return result

s = Solution()
print(s.restoreIpAddresses('0000'))
print(s.restoreIpAddresses('000'))
print(s.restoreIpAddresses('12345678'))