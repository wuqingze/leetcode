class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        i = m -1
        j = n - 1
        p = n + m -1
        while j>-1 and i > -1:
            if nums1[i] > nums2[j]:
                nums1[p] = nums1[i]
                i -= 1
                p -= 1
            else:
                nums1[p] = nums2[j]
                j -= 1
                p -= 1
        if j>-1:
            for k in range(j+1):
                nums1[k] = nums2[k]
s = Solution()
print(s.merge([1,0],1,[1],1))            