class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        t = digits[-1]+1
        jinwei = t//10
        digits[-1] = t%10
        n = len(digits)
        i = n-2
        
        while i>-1 and jinwei == 1:
            t = digits[i]+jinwei
            jinwei = t//10
            digits[i] = t%10
            i -= 1
            
        if jinwei == 1:
            return [1]+digits
        else:
            i = 0
            while digits[i] == 0:
                i += 1
            return digits[i:]
        # n = len(digits)
        # i = n -1
        # jinwei = 0
        # while True:
        #     t = (digits[i]+jinwei+1)
        #     jinwei = t//10
        #     digits[i] = t%10
        #     i -= 1
        #     if jinwei == 0 or i<0:
        #         break
         
            
        # if jinwei == 1:
        #     return [1].extend(digits)
        # else:
        #     i = 0
        #     while digits[i] == 0:
        #         i += 1
        #     return digits[i:]


s = Solution()
print(s.plusOne([9]))