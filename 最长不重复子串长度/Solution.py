class Solution:
    def __init__(self):
        self.max_str = ""
    
    def starindex(self,start,end,s,c):
        for i in range(start,end):
            if s[i] == c:
                return i+1
            
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == "":
            return 0
        if s == None:
            return 0
        start = 0
        end = 1
        length = len(s)
        while end < length:
            if s[end] in s[start:end]:
                start = self.starindex(start,end,s,s[end])
                
            elif len(s[start:end+1]) > len(self.max_str):
                self.max_str = s[start:end+1]
            end += 1
        if len(self.max_str)==0:
            return 1
        else:
            return len(self.max_str)

        