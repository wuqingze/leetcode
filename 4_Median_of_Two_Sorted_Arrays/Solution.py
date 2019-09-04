# 这道题分治和二分查找要成立的前提条件是要证明
# 存在i+j = (m-i)+(n-j),使得A[i-1]<=B[j]且B[j-1]<=A[i]
# 成立。
# 同时i,j使得左部分A[0:i],B[0:j]和右部分A[i:m],B[j:n]唯一存在
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n =  len(nums2)
        m = len(nums1)
        
        a0 = nums1[0]
        b0 = nums2[0]
        a1 = nums1[-1]
        b1 = nums2[-1]

        if a0 >= b1:
            i = (n+m-1)//2
            j = (n+m)//2
            if i < n and j<n:
                return (nums2[i]+nums2[j])/2
            elif i >=n and j>=n:
                return (nums1[i%n]+nums1[j%n])/2
            else:
                return (nums2[i]+nums1[j%n])
        elif b0>=a1:
            i = (n+m-1)//2
            j = (n+m)//2
            if i < m and j<m:
                return (nums1[i]+nums1[j])/2
            elif i >=m and j>=m:
                return (nums1[i%m]+nums1[j%m])/2
            else:
                return (nums2[i]+nums1[j%m])
        else:
            if m > n:
                t = nums1
                nums1 = nums2
                nums2 = t
                t = m
                m = n
                n = t

            s = 0
            e = m - 1
            while s <= e:
                i = (s+e)//2
                j = (n+m+1)//2 - i
                


        

                        
s = Solution()
print(s.findMedianSortedArrays([],[]))