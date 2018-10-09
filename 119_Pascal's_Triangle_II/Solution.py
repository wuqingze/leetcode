class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        t = []
        for i in range(rowIndex+1):
            tt = [1]* (i+1)
            for j in range(1,i):
                tt[j] = t[i-1][j-1]+t[i-1][j]
            t.append(tt)
        return t[-1]

s = Solution()
print(s.getRow(3))