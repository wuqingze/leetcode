class Solution(object):
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        s = set()
        for i in range(len(A)):
            if len(A[i]) <= 2:
                s.add(A[i])
            else:
                s.add(str(sorted(A[i])))
            
        return len(s)

s = Solution()
print(s.numSpecialEquivGroups( ["aa","bb","ab","ba"]))
