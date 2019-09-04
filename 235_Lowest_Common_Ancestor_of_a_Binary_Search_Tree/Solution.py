# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def ff(self,root,target,path):
        if root == None:
            pass
        if root.val == target.val:
            path.append(root.val)
        elif root.val < target.val:
            path.append(root.val)
            self.ff(root.right,target,path)
        else:
            path.append(root.val)
            self.ff(root.left,target,path)
            
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        pp = []
        qp = []
        self.ff(root,p,pp)
        self.ff(root,q,qp)
        ans = pp[0]
        for i in range(min(len(pp),len(qp))):
            if pp[i] != qp[i]:
                break
            else:
                ans = pp[i]
        return ans

root = TreeNode(6)
root.left = TreeNode(2)
root.right = TreeNode(8)
root.left.left = TreeNode(0)
root.left.right = TreeNode(4)
root.right.left = TreeNode(7)
root.right.right = TreeNode(9)
root.left.right.left = TreeNode(3)
root.left.right.right = TreeNode(5)
s  = Solution()
print(s.lowestCommonAncestor(root,2,8))