# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def tree(self,inorder,postorder,si,ei,sp,ep):
        if si > ei or sp>ep:
            return None
        elif si == ei:
            return TreeNode(inorder[si])
        
        root = TreeNode(postorder[ep])
        index = si
        for i in range(si,ei+1):
            if inorder[i] == postorder[ep]:
                index = i
                break
                
        root.left = self.tree(inorder,postorder,si,index-1,sp,sp+(index-si)-1)
        root.right = self.tree(inorder,postorder,index+1,ei,ep-ei+index,ep-1)
        return root
        
    def buildTree(self, inorder, postorder):
        return self.tree(inorder,postorder,0,len(inorder)-1,0,len(postorder)-1)

s = Solution()
print(s.buildTree( [9,3,15,20,7],[9,15,7,20,3]))