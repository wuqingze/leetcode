class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        n = len(pattern)
        strs = str.split()
        m = len(strs)
        if n != m:
            return False
        hm = {}
        patterns = [-1]*n
        for i in range(n):
            hm[pattern[i]] = hm.get(pattern[i],i)
            patterns[i] = hm[pattern[i]]
            
        for i in range(m):
            if strs[i] != strs[patterns[i]]:
                return False
            
        return True
s = Solution()
print(s.wordPattern("abba","dog dog dog dog"))