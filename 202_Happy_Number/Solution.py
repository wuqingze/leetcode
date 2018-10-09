class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        ht = set()
        while n != 1:
            if n in ht:
                return False
            t = 0
            while n != 0:
                tt = n % 10
                t += tt ** 2
                n //= 10
            if t == 1:
                return True
            else:
                ht.add(n)
                n = t
        return True
s = Solution()
print(s.isHappy(2))