# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        l1 = [root1]
        l2 = [root2]
        
        leaf1 = []
        leaf2 = []
        
        cur1 = root1
        cur2 = root2
        
        i1 = 0
        i2 = 0
        
        while cur1 != None:
            if cur1.left == None and cur1.right == None:
                leaf1.append(cur1.val)
                l1.append(None)
            elif cur1.left != None:
                l1.append(cur1.left)
            elif cur1.right != None:
                l1.append(cur1.right)
            i1 += 1
            cur1 = l1[i1]
        
        while cur2 != None:
            if cur2.left == None and cur2.right == None:
                leaf2.append(cur2.val)
                l2.append(None)
            elif cur2.left != None:
                l2.append(cur2.left)
            elif cur2.right != None:
                l2.append(cur2.right)
            i2 += 1
            cur2 = l2[i2]
        return leaf1 == leaf2
s = Solution()

s.leafSimilar()
        