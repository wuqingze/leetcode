class Solution(object):
    def dp(self,height,i,j,n):
        if i>=j:
            return 0
        t = 0
        if height[i]>height[j]:
            k = j
            while k >= 0 and height[j] >= height[k]:
                t += (height[j]-height[k])
                k -= 1
            return t + self.dp(height,i,k,n)
        else:
            k = i
            while k<=j and height[i]>=height[k]:
                t += (height[i]-height[k])
                k +=1
            return t + self.dp(height,k,j,n)
        
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        # n = len(height)
        # return self.dp(height,0,n-1,n)
        l = 0
        n = len(height)
        r = n-1
        ans = 0
        while l<r:
            if height[l] < height[r]:
                c = l
                #这里之前写c<n，是错的
                while c<=r and height[l]>=height[c]:
                    ans += (height[l]-height[c])
                    c += 1
                l = c
            else:
                c = r
                while c >=l and height[r]>=height[c]:
                    ans += (height[r]-height[c])
                    c -= 1
                r = c
        return ans
s = Solution()
# print(s.trap([5,5,1,7,1,1,5,2,7,6]))#23
print(s.trap([0,1,0,2,1,0,1,3,2,1,2,1]))