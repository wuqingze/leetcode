class Solution:
    def backtraking(self,ans,left,right,n,cur):
        if n*2 == len(cur):
            ans.append(cur)
            return
            
        if left < n:
            self.backtraking(ans,left+1,right,n,cur+'(')
        if right < left:
            self.backtraking(ans, left, right+1,n,cur+')')
            
    def generateParenthesis(self, n):
        ans = []
        self.backtraking(ans,0,0,n,'')
        return ans

if __name__ == "__main__":
    s = Solution()
    print(s.generateParenthesis(3))