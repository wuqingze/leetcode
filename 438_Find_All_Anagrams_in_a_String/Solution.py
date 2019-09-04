class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        n = len(s)
        m = len(p)
        if n<m:
            return []
        
        s = set()
        s.add(''.join(sorted(p)))
        ans = []
        for i in range(n-m):
            a = list(s[i:i+m])
            # t = sorted(list(s[i:i+m]))
            # t = ''.join(t)
            if t in s:
               ans.append(i)
            
        return ans

s = Solution()
print(s.findAnagrams("cbaebabacd","abc"))