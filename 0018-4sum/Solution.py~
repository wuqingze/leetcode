class Solution:
    def fourSum(self, nums, target):
        if None == nums or [] == nums:
            return []
        
        n = len(nums)
        if n < 4:
            return []
        
        ans = []
        nums = sorted(nums)
        count = {}
        for i in range(n):
            count[nums[i]] = count.get(nums[i],0)+1

        middleResult = {}
        for i in range(n):
            for j in range(i+1,n):
                t = middleResult.get(nums[i]+nums[j],[])
                if [nums[i],nums[j]] not in t:
                    t.append([nums[i],nums[j]])

                middleResult[nums[i]+nums[j]] = t
        for k,v in middleResult.items():
            if middleResult.get(k) == None:
                continue

            if k + k == target:
                l = v
                for t in l:
                    if t[0] == t[1] and count[t[0]]>3:
                        ans.append([t[0]]*4)
                    elif t[0] != t[1] and count[t[0]]>1 and count[t[1]]>1:
                        tt = [t[0],t[0],t[1],t[1]]
                        ans.append(tt)
            else:
                if target - k in middleResult:
                    l1 = v
                    l2 = middleResult[target - k]

                    for item1 in l1:
                        for item2 in l2:
                            cc = {}
                            for vv in item1:
                                cc[vv] = cc.get(vv,0)+1
                            for vv in item2:
                                cc[vv] = cc.get(vv,0)+1
                            isOk = True
                            for kk,vv in cc.items():
                                if count[kk] < cc[kk]:
                                    isOk = false
                                    break
                            if isOk:
                                tt = [item1[0],item1[1],item2[0],item2[1]]
                                tt = sorted(tt)
                                if tt not in ans:
                                    ans.append(tt)

        return ans



s = Solution()
print(s.fourSum([1,0,-1,0,-2,2],0))
