class Solution:

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []

        r = []
        map_ = {}
        c = {}
        for i in range(len(nums)):
            if c.get(nums[i]) == None:
                c[nums[i]] = 1
            else:
                c[nums[i]] = c[nums[i]] + 1

        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                t = nums[i]+nums[j]
                if map_.get(t) == None:
                    map_[t] = sorted([[nums[i], nums[j]]])
                elif sorted([nums[i], nums[j]]) not in map_.get(t):
                    a = map_.get(t)
                    a.append(sorted([nums[i], nums[j]]))
                    map_[t] = a

        for i in range(len(nums)):
            t = 0 - nums[i]
            if map_.get(t) != None:
                t = map_.get(t)
                for j in range(len(t)):
                    if nums[i] not in t[j]:
                        x = [nums[i]]
                        x.extend(t[j])
                        a = sorted(x)
                        if a not in r:
                            r.append(a)
                    elif c.get(nums[i]) > 1:
                        x = [nums[i]]
                        x.extend(t[j])
                        a = sorted(x)
                        if a not in r:
                            r.append(a)

        return r
def main():
    print(Solution().threeSum([-1, 0, 1, 2, -1, -4]))

if __name__ == '__main__':
    main()
        
