class Solution(object):
    # def matrixScore(self, A):
    #     R, C = len(A), len(A[0])
    #     ans = 0
    #     for c in range(C):
    #         col = 0
    #         for r in range(R):
    #             col += A[r][c] ^ A[r][0]
    #         ans += max(col, R - col) * 2 ** (C - 1 - c)
    #     return ans
    def matrixScore(self, A):
        M, N = len(A), len(A[0])
        res = (1 << N - 1) * M
        for j in range(1, N):
            cur = sum(A[i][j] == A[i][0] for i in range(M))
            res += max(cur, M - cur) * (1 << N - 1 - j)
        return res

s = Solution()
print(s.matrixScore([[0,1,1,0],[1,1,1,0],[1,1,1,0]]))