class Solution:
    def f(self, i, n, k, c, tList, result):
        if i == n:
            if c == k -1:
                tList.append(i)
                result.append([l for l in tList])
                tList.pop()
                return
            else:
                return 
        if c == k -1:
            tList.append(i)
            result.append([l for l in tList])
            tList.pop()
            self.f(i+1, n, k, c, tList, result)
        else:
            tList.append(i)
            self.f(i+1, n, k, c+1, tList, result)
            tList.pop()
            self.f(i+1, n, k, c, tList, result)
            
    def combine(self, n, k):
        if n == 0 or k == 0:
            return []
        tList = []
        result = []
        self.f(1, n, k, 0, tList, result)
        return result
s = Solution()
print(s.combine(4,2))