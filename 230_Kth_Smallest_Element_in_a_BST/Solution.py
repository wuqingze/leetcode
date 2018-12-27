import heapq
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.k = 0
    def dfs(self,root):
        if self.k == 1:
            return root.val
        elif root.left == None and root.right == None:
            self.k -= 1
        else:
            if root.right:
                self.dfs(root.right)
            if root.left:
                self.k -= 1
                self.dfs(root.left)
    def def1(self,root,t):
        if root == None:
            return
        heapq.heappush(t,root.val)
        self.def1(root.left,t)
        self.def1(root.right,t)


    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        # self.k = k
        # return self.dfs(root)

        # 方法一，使用优先队列
        # 方法二，使用前序遍历

        # 方法一：
        # t = []
        # self.def1(root,t)
        # return heapq.nsmallest(k,t)[-1]

        # 方法二：
        if root == None:
            return None

        stack = []
        count = 0
        node = root
        while stack or node:
            if node != None:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                count += 1
                if count == k:
                    return node.val
                node = node.right


s = Solution()
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)

print(s.kthSmallest(root,1))