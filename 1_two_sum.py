class Solution:
	def twoSum(self, nums, target):
		l = []
		i = 0
		for n in nums:
			l.append((n,i))
			i += 1
		l = sorted(l, key = lambda t: t[0])
		nums_len = len(nums)
		for i in range(nums_len):
			start = i + 1
			end = nums_len -1
			while start <= end:
				middle = (start+end)//2
				if l[middle][0] + l[i][0] == target:
					return sorted([l[i][1],l[middle][1]])
				elif l[middle][0] + l[i][0] < target:
					start = middle + 1
				else:
					end = middle - 1

if __name__ == '__main__':
	# nums = [2, 7, 11, 15]
	# target = 9

	nums = [0,4,3,0]
	target = 0
	s = Solution()
	print(s.twoSum(nums,target))

