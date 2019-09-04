# class Solution:
#     def topKFrequent(self, nums, k):
#         """
#         :type nums: List[int]
#         :type k: int
#         :rtype: List[int]
#         """
#         hm = {}
#         for i in range(len(nums)):
#             hm[nums[i]] = hm.get(nums[i],0)+1
            
#         s = {}
#         c = 0
#         mn = 0
#         t = -1
#         for key,v in hm.items():
#             if c < k:
#                 if mn < v:
#                     mn = v
#                     t = key
#                 s[key] = v
#                 c += 1
#             else:
#                 if mn < v:
#                     del s[t]
#                     mn = v
#                     t = key
#                     s[key] = v
                    
#         ans = []
#         for key,v in s.items():
#             ans.append(key)
#         return ans
                    

# s = Solution()
# print(s.topKFrequent([4,1,-1,2,-1,2,3],2))


import heapq
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        m = {}
        for i in nums:
            m[i] = m.get(i,0)+1
            
        heapq.heapify(m.items(),lambda k,v: v)
        return heapq.nlargest(k,nums.items())
s = Solution()
print(s.topKFrequent([1,1,1,2,2,3],2))