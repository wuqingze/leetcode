class Solution:
    def intToRoman(self, num):
        rn = [('M',1000)
,('D',500)
,('C',100)
,('L',50)
,('X',10)
,('V',5)
,('I',1)]
        
        result = ''
        for t in rn:
            result += t[0]*(num//t[1])
            num //= t[1]
            
        return result
        
s = Solution()
print(s.intToRoman(3))