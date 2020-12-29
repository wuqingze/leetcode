class Solution:
    def grayCode(self, n: int):
        result = [0]
        for i in range(n):
            l = len(result)
            for j in range(l-1,-1,-1):
                result.append(result[j] ^ (1<<i))

        return result

s = Solution()
for i in range(12):
    print(s.grayCode(i))
# print(s.grayCode(0))
# print(s.grayCode(1))
# print(s.grayCode(2))
# print(s.grayCode(3))


