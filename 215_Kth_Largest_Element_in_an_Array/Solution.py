class Solution(object):
    def qs(self,nums,l,r,k):
        i = l
        j = r-1
        pivot = nums[j]
        while i<j:
            if nums[i] > pivot:
                self.swap(nums,i,j)
                i += 1
                j -= 1
            else:
                i += 1
        if r-l-i-1 == k:
            return nums[i]
        elif r-l-i < k:
            return self.qs(nums,l,i+1,k-(r-l-i))
        else:
            return self.qs(nums,i+1,r,k)
        
        
    def swap(self,a,i,j):
        t = a[i]
        a[i]= a[j]
        a[j] = t
            
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # heapq.heapify(nums)
        # return heapq.nlargest(k,nums)[-1]
        
        return self.qs(nums,0,len(nums),k)

s = Solution()
# print(s.findKthLargest([3,2,1,5,6,4],2))
print(s.findKthLargest([3,2,3,1,2,4,5,5,6],4))