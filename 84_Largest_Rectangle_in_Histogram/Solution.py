class Solution:
    def largestRectangleArea(self, heights):
        if heights == None or len(heights) == 0:
            return 0


        n = len(heights)        
        stck = []
        mx = 0
        for i in range(n):
            j = i
            t = 0
            while j>-1 and heights[i] <= heights[j]:
                heights[j] = heights[i]
                t += 1
                j -= 1

            mx = max(mx, t* heights[i])
        for i in range(n):
            mx = max(mx, heights[i]*(n-i))

        return mx
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
print(s.largestRectangleArea([2,1,5,6,2,3]))
