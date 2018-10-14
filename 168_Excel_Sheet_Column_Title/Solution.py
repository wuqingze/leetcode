class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        t = ['Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y']
        if n < 27:
            return t[n%26]
        
        ans = ''
        while n > 0:
            ans = t[n%26]+ans
            n //= 26
        return ans

s = Solution()
print(s.convertToTitle(52))