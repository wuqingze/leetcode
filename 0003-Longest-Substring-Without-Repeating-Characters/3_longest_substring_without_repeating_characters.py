class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if length < 2:
            return length

        dct = {}
        max_ = 0
        last_cur = 0
        cnt = 0
        j = 0
        for i in range(length):
            if dct.get(s[i]) != None:
                if max_ < i - dct[s[i]]:
                    max_ = max(i-j,max_)
                last_cur = i
                cnt = 1
                j = i
            else:
                cnt += 1
            dct[s[i]] = i
            
        return max(length-j, max_)
        
if __name__ == '__main__':
    s = Solution()
    print(s.lengthOfLongestSubstring("abba"))
        