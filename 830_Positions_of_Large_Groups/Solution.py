class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        ans = []
        t = S[0]
        c = 0
        n = len(S)
        j = 0
        for i in range(n):
            if S[i] == t:
                c += 1
            else:
                if c >= 3:
                    ans.append([j,i-1])
                else:
                    j = i
                    c = 1
                    t = S[i]
        return ans

s = Solution()
print(s.largeGroupPositions("abbxxxxzzy"))