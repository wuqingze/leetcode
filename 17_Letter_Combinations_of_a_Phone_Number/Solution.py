class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits == None and digits == '':
            return []
        
        m = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],'8':['t','u','v'],'9':['x','y','z']}
        ans = ['']
        n = len(digits)
        for i in range(n):
            t = []
            for c in ans:
                for cc in m[digits[i]]:
                    t.append(c+cc)
                    
            ans = t
        return ans
s = Solution()
print(s.letterCombinations("233"))