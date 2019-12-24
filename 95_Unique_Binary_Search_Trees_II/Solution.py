class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def f(self, i, j, array):
        if i > j:
            return [None]
        if i == j:
            return [TreeNode(array[i])]
        result = []
        for k in range(i, j+1):
            leftNodes = self.f(i, k-1, array)
            rightNodes = self.f(k+1, j, array)
            for lnode in leftNodes:
                for rnode in rightNodes:
                    node = TreeNode(array[k])
                    node.left = lnode
                    node.right = rnode
                    result.append(node)
        return result

    def generateTrees(self, n):
        if n == 0:
            return []
        array = [i for i in range(1,n+1)]
        return self.f(0, n-1, array) 

s = Solution()
def preList(head):
    if head:
        print(head.val, end=',')
    else:
        print('null', end=',')
    if head:
        preList(head.left)
        preList(head.right)

for i in range(1,5):
    nodeList = s.generateTrees(i)
    for head in nodeList:
        preList(head)
        print("")
