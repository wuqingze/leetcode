class Solution:
    def longestValidParentheses(self, s):
        if None == s or '' == s:
            return None

        n = len(s)
        if n == 1:
            return None

        stk = [[-1,')']]
        mx = 0
        for i in range(n):
            if s[i] == ')' :
                if stk[-1][1] == '(':
                    stk.pop()
                    mx = max(i-stk[-1][0], mx)
                else:
                    stk.append([i,')'])
            else:
                stk.append([i,'('])

        return mx


if __name__ == '__main__':
    s = Solution()
    print(s.longestValidParentheses('(()'))
    print(s.longestValidParentheses(')()())'))
