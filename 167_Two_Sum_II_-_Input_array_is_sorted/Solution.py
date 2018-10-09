class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = len(numbers)
        i = 0
        j = n-1
        mid = (j-i)//2
        while i < j:
            if numbers[i] + numbers[j] == target:
                return [i][j]
            elif numbers[i] + numbers > target:
                return []
            else:
                if numbers[i] + numbers[mid] == target:
                    return [i,mid]
                elif numbers[i]+numbers[mid]:
                    pass
        return []
s = Solution()
print(s.twoSum([2,3,4],6))