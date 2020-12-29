class Solution:
    def backtracking(self, candidates, i, pre, preline, result, n, target):
        if i >= n:
            return

        if candidates[i] + pre == target:
            preline.append(candidates[i])
            if preline not in result:
                result.append([ii for ii in preline])
            preline.pop()
            return
        elif candidates[i] + pre < target:
            self.backtracking(candidates, i+1, pre, preline, result, n, target)
            preline.append(candidates[i])
            self.backtracking(candidates, i+1, pre+candidates[i], preline, result, n, target)
            preline.pop()
            return
        else:
            return
    def combinationSum2(self, candidates, target):
        if None == candidates or [] == candidates:
            return []

        i = 0
        pre = 0
        preline = []
        result = []
        n = len(candidates)
        candidates = sorted(candidates)
        self.backtracking(candidates, i,pre,preline, result, n, target)
        return result


s = Solution()
print(s.combinationSum2( [10,1,2,7,6,1,5], 8))
