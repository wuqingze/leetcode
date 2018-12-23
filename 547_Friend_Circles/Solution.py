class Solution:
    def __init__(self):
        self.count = 0
        self.id = []
        self.sz = []
    def uf(self,n):
        self.count = n
        self.sz = [1]*n
        self.id = [i for i in range(n)]
        
    def getCount(self):
        return self.count
    
    def find(self,x):
        while x != self.id[x]:
            self.id[x] = self.id[self.id[x]]
            x = self.id[x]
            
        return x
    def connected(self,p,q):
        return self.find(p) == self.find(q)
    
    def union(self,p,q):
        pid = self.find(p)
        qid = self.find(q)
        if pid == qid:
            return
        
        if self.sz[p] < self.sz[q]:
            self.id[p] = qid
            self.sz[q] += self.sz[p]
        else:
            self.id[q] = pid
            self.sz[p] += self.sz[q]
            
        self.count -= 1
        
        
    def dfs(self,a,i,n,dp):
        if i in dp:
            return
        dp.add(i)
        for j in range(i+1,n):
            if a[i][j] != 0:
                self.dfs(a,j,n,dp)
            
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        n = len(M)
        self.uf(n)
        for i in range(n):
            for j in range(i,n):
                if M[i][j] == 1:
                    if not self.connected(i,j):
                        self.union(i,j)
                    
        return self.count

s = Solution()
# print(s.findCircleNum([[1,1,0],[1,1,0],[0,0,1]]))
# print(s.findCircleNum([[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]))
print(s.findCircleNum(    [[1,1,0,0,0,0,0,1,0,0,0,0,0,0,0],
    [1,1,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,1,0,1,1,0,0,0,0,0,0,0,0],
    [0,0,0,0,1,0,0,0,0,1,1,0,0,0,0],
    [0,0,0,1,0,1,0,0,0,0,1,0,0,0,0],
    [0,0,0,1,0,0,1,0,1,0,0,0,0,1,0],
    [1,0,0,0,0,0,0,1,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,1,1,1,0,0,0,0,1,0],
    [0,0,0,0,1,0,0,0,0,1,0,1,0,0,1],
    [0,0,0,0,1,1,0,0,0,0,1,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,0,0,0,0,1,0,1,0,0,0,0,1,0],
    [0,0,0,0,0,0,0,0,0,1,0,0,0,0,1]]))