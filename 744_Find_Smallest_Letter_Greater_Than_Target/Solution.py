class Solution:
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        mnc = ord('z')
        ans = 'z'
        for i in range(len(letters)):
            if ord(letters[i]) < ord(target) and ord(letters[i]) < mnc:
                ans = letters[i]
                mnc = ord(ans)
        return ans

s = Solution()
print(s.nextGreatestLetter(["c","f","j"],''))