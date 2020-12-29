# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def __init__(self):
        self.firstNode = None
        self.secondNode = None
        self.preNode = TreeNode(-9999999999999999999)

    def f(self, root):
        if root == None:
            return
        self.f(root.left)
        if self.firstNode == None and self.preNode.val >= root.val:
            self.firstNode = self.preNode
        if self.firstNode != None and self.preNode.val >= root.val:
            self.secondNode = root

        self.preNode = root
        self.f(root.right)

    def recoverTree(self, root):
        if root == None:
            return root
        self.f(root)
        temp = self.firstNode.val
        self.firstNode.val = self.secondNode.val
        self.secondNode.val = temp
def inList(root):
    if root == None:
        return
    inList(root.left)
    print(root.val, end=',')
    inList(root.right)

s = Solution()
# root = TreeNode(1)
# root.left = TreeNode(3)
# root.left.right = TreeNode(2)
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.right.left = TreeNode(2)

s.recoverTree(root)
inList(root)
