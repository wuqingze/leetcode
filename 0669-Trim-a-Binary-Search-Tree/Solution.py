# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def trimBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: TreeNode
        """
        if root == None:
            return root
        if root.val >= L and root.val <= R:
            root.left = self.trimBST(root.left,L,R)
            root.right = self.trimBST(root.right,L,R)
            return root
        elif root.val < L:
            return self.trimBST(root.right,L,R)
        else:
            return self.trimBST(root.left,L,R)

root = TreeNode(1)
left = TreeNode(0)
right = TreeNode(2)
root.left = left
root.right =  right
s = Solution()
t = s.trimBST(root,1,2)
