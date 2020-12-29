class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if s == None or t == None or len(s) == 0 or len(t) == 0 or len(s)<len(t):
            return ""


        dictT = {}
        for i in range(len(t)):
            dictT[t[i]] = dictT.get(t[i],0) + 1


        required = len(dictT)
        formed = 0
        slideWindow = {}
        l = 0
        r = 0
        ans = [-1,-1,-1]
        n = len(s)
        
        while r<n:
            slideWindow[s[r]] = slideWindow.get(s[r],0)+1
            if s[r] in dictT and slideWindow[s[r]] == dictT[s[r]]:
                formed += 1

            while formed == required:
                if ans[0] == -1 or r-l<ans[2]-ans[1]:
                    if ans[0] == -1:
                        ans[0] = 0
                    ans[2] = r
                    ans[1] = l


                slideWindow[s[l]] -= 1
                if s[l] in dictT and slideWindow[s[l]] < dictT[s[l]]:
                    formed -= 1
                l += 1

            r += 1

        if ans[0] == -1:
            return ""
        else:
            return s[ans[1]:ans[2]+1]



# 当S的长度明显比T长或者S中的绝大部分元素不再T中的时候，我们可以通过提取S中的T元素组成新的数组SS，然后在SS的基础上进行滑动窗口。
# We create a list called filtered_S,filtered_S which has all the characters from string S along with their indices in SS, 
# but these characters should be present in TT.

# S = "ABCDDDDDDEEAFFBC" T = "ABC"
# filtered_S = [(0, 'A'), (1, 'B'), (2, 'C'), (11, 'A'), (14, 'B'), (15, 'C')]
# Here (0, 'A') means in string S character A is at index 0.
