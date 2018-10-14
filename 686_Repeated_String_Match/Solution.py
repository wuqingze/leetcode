class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        san = len(set(A))
        sbn = len(set(B))
        
        if san < sbn:
            return -1
        
        na = len(A)
        nb = len(B)
        for i in range(nb):
            if B[i] not in A:
                return -1
        
        if na >= nb:
            if B in A:
                return 1
            else:
                if B in A+A:
                    return 2
                else:
                    return -1
                
        t = B.split(A)
        for i in range(len(t)):
            if t[i] not in A:
                return -1
            
        return len(t)+(nb-(len(t[0])+len(t[-1])))//na
        
        
s = Solution()
print(s.repeatedStringMatch("a","aa"))