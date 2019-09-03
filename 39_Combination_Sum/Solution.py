import logging

class Solution:
    def backtrack(self, candidates, target, result, i, pre, preline, n):
        logging.debug("target:{},result:{},i:{},pre:{},preline:{},n:{}".format(candidates,target,result,i,pre,preline,n))
        t = target - pre
        c = t//candidates[i]
        for j in range(c+1):
            if candidates[i]*j + pre == target:
                for jj in range(j):
                    preline.append(candidates[i])
                if preline not in result:
                    result.append([k for k in preline])
                for jj in range(j):
                    preline.pop()
            elif candidates[i]*j + pre < target:
                if i+1 < n:
                    for jj in range(j):
                        preline.append(candidates[i])  
                    self.backtrack(candidates, target, result, i+1, candidates[i]*j + pre, preline,n)
                    for jj in range(j):
                        preline.pop()

    def combinationSum(self, candidates, target):
        result = []
        i = 0
        pre = 0
        preline = [] 
        n = len(candidates)
        self.backtrack(candidates, target, result, i, pre, preline, n)
        return result

if __name__ == '__main__':
    logging.FileHandler("my.log",encoding='utf-8')
    s = Solution()
    # print(s.combinationSum([2,3,6,7],7))
    print(s.combinationSum([2,3,5],8))
