class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        n = len(ransomNote)
        m = len(magazine)
        if n > m:
            return False
        sr = {}
        sm = {}
        for i in range(n):
            if sr.get(ransomNote[i]) == None:
                sr[ransomNote[i]] = 1
            else:
                sr[ransomNote[i]] = sr[ransomNote[i]]+  1
        for i in range(m):
            if sm.get(magazine[i]) == None:
                sm[magazine[i]] = 1
            else:
                sm[magazine[i]] = sm[magazine[i]] + 1
        for key,value in sr.items():
            if sm.get(key) == None or sm[key] < value:
                return False
            
        return True

s = Solution()
print(s.canConstruct('aa','ab'))