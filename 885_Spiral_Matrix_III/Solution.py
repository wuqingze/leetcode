class Solution:
    def spiralMatrixIII(self, R, C, r, c):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        res = [[r, c]]
        x, y, n, i = 0, 1, 0, 0
        while len(res) < R * C:
            r, c, i = r + x, c + y, i + 1
            if 0 <= r < R and 0 <= c < C:
                res.append([r, c])
            if i == n / 2 + 1:
                x, y, n, i = y, -x, n + 1, 0
        return res

s = Solution()
print(s.spiralMatrixIII(5,6,1,4))