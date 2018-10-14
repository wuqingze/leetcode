class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
        t = ''
        for i in range(len(s)):
            if s[i] in d:
                t += s[i]
        t = t.lower()
        i = 0
        n = len(t)
        j = n  -1
        while i <=j:
            if t[i] != t[j]:
                return False
            i += 1
            j -= 1
        return True

s = Solution()
print(s.isPalindrome("0P"))