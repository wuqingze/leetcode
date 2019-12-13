class Solution:
        def isScramble(self, s1, s2) -> bool:
            if s1 == None:
                return False
            if s2 == None:
                return False

            n = len(s1)
            m = len(s2)
            if n != m:
                return False
            tmap1 = {}
            tmap2 = {}
            for c in s1:
                tmap1[c] = tmap1.get(c, 0)+1
            for c in s2:
                tmap2[c] = tmap2.get(c,0) + 1
            if len(tmap1) != len(tmap2):
                return False
            for k,v in tmap1.items():
                if v != tmap2(k):
                    return False
            if s1 == s2:
               return True
            for i in range(1,n):
                if self.isScramble(s1[0:i], s2[0:i]) and self.isScramble(s1[i:n], s2[i:n]):
                    return True
                if self.isScramble(s1[0:i], s2[n-i:n]) and self.isScramble(s1[i:n], s2[0:n-i]):
                    return True
            return False
                
s = Solution()
# print(s.isScramble('great', 'rgeat'))
print(s.isScramble('abcde', 'caebd'))
                    
