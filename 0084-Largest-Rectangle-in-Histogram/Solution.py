class Solution:
    def largestRectangleArea(self, heights):
        if heights == None or len(heights) == 0:
            return 0

        n = len(heights)
        leftdp = [-1 for i in range(n)]
        for i in range(1, n):
            p = i -1
            while p >=0 and heights[p] >= heights[i]:
                p = leftdp[p]
            leftdp[i] = p
        rightdp = [n for i in range(n)]
        for i in range(n-2, -1, -1):
            p = i + 1
            while p<=n-1 and heights[p] >= heights[i]:
                p = rightdp[p]
            rightdp[i] = p

        mx = 0
        for i in range(n):
            mx = max(mx, heights[i] * (rightdp[i] - leftdp[i] -1))
    
        return   mx
        
        # rightdp = []
        # n = len(heights)        
        # stck = []
        # mx = 0
        # for i in range(n):
        #     j = i
        #     t = 0
        #     while j>-1 and heights[i] <= heights[j]:
        #         heights[j] = heights[i]
        #         t += 1
        #         j -= 1

        #     mx = max(mx, t* heights[i])
        # for i in range(n):
        #     mx = max(mx, heights[i]*(n-i))

        # return mx
        # for i in range(n):
        #     t = 0
        #     while len(stck) !=0 and heights[i] <= stck[-1]:
        #         t += 1
        #         stck.pop()
        #     if len(stck) > 0:
        #         mx = max(mx, (t+1)* heights[i], (t+2)*stck[-1])
        #     else:
        #         mx = max(mx, (t+1)*heights[i])
        #     stck.append(heights[i])
        # return mx

s = Solution()
# print(s.largestRectangleArea([2,1,5,6,2,3]))
# print(s.largestRectangleArea([2,4]))
print(s.largestRectangleArea([2,3]))
