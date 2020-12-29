# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def xx(self,root,hm,mx):
        if root == None:
            pass
        else:
            hm[root.val] = hm.get(root.val,0) + 1
            if hm[root.val] > mx.val:
                mx.val = hm[root.val]
            self.xx(root.left,hm,mx)
            self.xx(root.right,hm,mx)
            
        
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        
        mx = TreeNode(0)
        hm = {}
        self.xx(root,hm,mx)
        ans = []
        for key,val in hm.items():
            if val == mx.val:
                ans.append(key)
        return ans

root = TreeNode(2147483647)
# root.left = TreeNode(3)
# root.right = TreeNode(6)
# root.left.left = TreeNode(2)
# root.left.right = TreeNode(4)
# root.right.left = TreeNode(6)
# root.right.right = TreeNode(7)
# root.left.right.left = TreeNode(4)
# root.left.right.right = TreeNode(4)
# root.right.left.left = TreeNode(6)
s = Solution()
print(s.findMode(root))