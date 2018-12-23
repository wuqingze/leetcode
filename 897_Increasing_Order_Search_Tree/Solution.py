# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def dfs(self,root,contain):
        if root == None:
            return
        if root.left == None and root.right == None:
            contain.append(root)
            return
        self.dfs(root.left,contain)
        contain.append(root)
        self.dfs(root.right,contain)
        
        
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        contain = []
        self.dfs(root,contain)
        result = contain[0]
        for i in range(1,len(contain)):
            contain[i-1].right = contain[i]
        return result

root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(6)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.right.right = TreeNode(8)
root.left.left.left = TreeNode(1)
root.right.right.left = TreeNode(7)
root.right.right.right = TreeNode(9)


s = Solution()
# print(s.increasingBST(root))
result = s.increasingBST(root)
while result:
    print(result.val)
    result = result.right