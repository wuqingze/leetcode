# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        elif root.left == None and root.right == None:
            return 1
        elif root.left == None or root.right == None:
            t = -1
            if root.right ==None:
                t = self.minDepth(root.left)
            else:
                t = self.minDepth(root.right)
            return 1 + t
        else:
            return 1 + min(self.minDepth(root.left),self.minDepth(root.right))

s = Solution()
root = TreeNode(1)
root.right = TreeNode(2)
print(s.minDepth(root))