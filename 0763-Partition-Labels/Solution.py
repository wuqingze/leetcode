class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        ans = []
        last = {}
        for i in range(len(S)):
            last[S[i]] = i
        
        j,k = 0,0
        for i in range(len(S)):
            k = max(i,last[S[i]])
            if k == i:
                ans.append(k-j+1)
                j = i+1
        return ans

s = Solution()
print(s.partitionLabels("ababcbacadefegdehijhklij"))