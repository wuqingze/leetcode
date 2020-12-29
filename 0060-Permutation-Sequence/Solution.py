class Solution:

    def getPermutation(self,n,k):

        jiecheng = {}
        for i in range(1,10):
            t = 1
            for j in range(1,i+1):
                t *= j

            jiecheng[i] = t

        nums = [i for i in range(1,n+1)]
        c = n
        while k > 1:
            if jiecheng[c]>k:
                if jiecheng[c-1] > k:
                    c -= 1
                    continue
                elif jiecheng[c-1] == k:
                    c -= 1

            shit = (k-1) // jiecheng[c-1]

            temp = nums[n-c+shit]
            for i in range(n-c+shit,n-c,-1):
                nums[i] = nums[i-1]
            nums[n-c] = temp
            k = k - jiecheng[c-1]*shit
        result = ''
        for i in nums:
            result += str(i)

        return result

s = Solution()
print(s.getPermutation(3,3,))
print(s.getPermutation(4,9))
print(s.getPermutation(3,2))
print(s.getPermutation(3,4))
print(s.getPermutation(4,7))
print(s.getPermutation(2,2))