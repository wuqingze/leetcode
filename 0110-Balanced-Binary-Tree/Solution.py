# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.mnd = 0x7fffffff
        self.mxd = -1
        self.m = {}
        
    def mn(self,root):
        if root == None:
            return 0
        
        if root.left == None or root.right == None:
            return 1
        
        return min(self.mn(root.left),self.mn(root.right))+1
        
        
    
    def mx(self,root):
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 1
        
        return max(self.mx(root.left),self.mx(root.right))+1
    
    
    def depth(self,root):
        if root == None:
            return 0
        elif self.m.get(root,None):
            return self.m.get(root)
        else:
            t =  1 + max(self.depth(root.left),self.depth(root.right))
            self.m[root] = t
            return t
        
    def isBalanced(self, root: TreeNode) -> bool:
        if root == None:
            return True
        elif root.left == None and root.right == None:
            return True
        
        return abs(self.depth(root.left)-self.depth(root.right)) < 2 and self.isBalanced(root.left) and self.isBalanced(root.right)
        