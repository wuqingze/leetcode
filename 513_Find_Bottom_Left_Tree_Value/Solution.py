# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        q = [root]
        i = 0
        size = 1
        while i<size:
            cur = q[i]
            if cur.right != None:
                q.append(cur.right)
                size += 1
            if cur.left != None:
                q.append(cur.left)
                size += 1
            i += 1
            
        return q[-1].val
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.right.left = TreeNode(5)
root.right.right = TreeNode(6)
root.right.left.left = TreeNode(7)
s = Solution()
print(s.findBottomLeftValue(root))