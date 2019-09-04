class Solution:
    
    def romanToInt(self, s: str) -> int:
        cm = {
                'I':1,
                'V':5,
                'X':10,
                'L':50,
                'C':100,
                'D':500,
                'M':1000,
                'IV':4,
                'IX':9,
                'XL':40,
                'XC':90,
                'CD':400,
                'CM':900,
             }
        
        i = 0
        n = len(s)
        count = 0
        while i<n:
            if i<n-1:
                if cm.get(s[i:i+2],None):
                    count += cm.get(s[i:i+2])
                    i += 2
                else:
                    count += cm.get(s[i])
                    i += 1
            else:
                count += cm.get(s[i])
                i += 1
                
        return count
            