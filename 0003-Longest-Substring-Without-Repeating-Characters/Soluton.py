class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n = len(nums1)
        m = len(nums2)
        t = []
        
        i = 0
        j = 0
        while i<n or j<m:
            if i<n and j <m:
                if nums1[i]<nums2[j]:
                    t.append(nums1[i])
                    i += 1
                else:
                    t.append(nums2[j])
                    j += 1
            elif i<n:
                t.append(nums1[i])
                i += 1
            else:
                t.append(nums2[j])
                j += 1
            w
        if (n+m)%2 == 0:
            xx = t[(n+m)//2]+t[(n+m)//2-1]
            return xx/2
        else:
            return t[(n+m)//2]


s = Solution()
print(s.findMedianSortedArrays([1,2],[3,4]))